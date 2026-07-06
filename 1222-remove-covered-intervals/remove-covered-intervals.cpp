using int2=pair<int, int>;
class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int n=intervals.size();
        vector<int2> I(n);
        int i=0;
        for(const auto& ii : intervals){
            const int a=ii[0], b=ii[1];
            I[i++]={a, b};
        }
        sort(I.begin(), I.end());
        auto [a, b]=I[0];
        int cnt=1;
        for(int i=1; i<n; i++){
            auto [c, d]=I[i];
            if (c>a && d>b){
                a=c;
                cnt++;
            }
            b=max(b, d);
        }
        return cnt;
    }
    
};