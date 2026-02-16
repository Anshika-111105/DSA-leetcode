class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int res = 0;
        for (int curr_end = 0, i = 0, n = clips.size(); curr_end < time; ++res) {
            int farthest = curr_end;
            while (i < n && clips[i][0] <= curr_end) {
                farthest = max(farthest, clips[i][1]);
                ++i;
            }
            if (farthest == curr_end) return -1;
            curr_end = farthest;
        }
        return res;
    }
};