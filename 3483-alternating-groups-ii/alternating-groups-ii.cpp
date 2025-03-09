class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(),colors.begin(),colors.begin() + k);
        int n=colors.size();
        if (k>n)
            return 0;
        int cnt=0;
        int ans=0;
        for (int i=1; i < n; i++) {
            if (colors[i - 1]!=colors[i]) {
                cnt++;
            } else {
                cnt=1;
            }
            if (cnt>=k) {
                ans++;
            }
        }
        return ans;
    }
};