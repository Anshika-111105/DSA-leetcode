class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        unordered_map<int, int> freq;

        for (int x : planks)
            freq[x]++;

        vector<int> unique;

        unordered_map<int, int> score;

        for (auto &[h, cnt] : freq) {
            unique.push_back(h);
            score[h] = cnt;
        }

        int m = unique.size();

        for (int i = 0; i < m; i++) {

            int x = unique[i];

            if (freq[x] >= 2)
                score[2 * x] += freq[x] / 2;

            for (int j = i + 1; j < m; j++) {

                int y = unique[j];

                score[x + y] += min(freq[x], freq[y]);
            }
        }

        int ans = 0;

        for (auto &[width, cnt] : score)
            ans = max(ans, cnt);

        return ans;
    }
};