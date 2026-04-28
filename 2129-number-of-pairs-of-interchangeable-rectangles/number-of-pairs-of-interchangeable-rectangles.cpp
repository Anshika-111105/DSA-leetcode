class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        unordered_map<double, double> mp;
        long long ans = 0;
        for(int i = n-1; i >= 0;i--){
            double ratio = (double)rectangles[i][0]/(double)rectangles[i][1];
            if(mp.find(ratio)!=mp.end()){
                ans+=mp[ratio];
            }
            mp[ratio]++;

        }
        return ans;

    }
};