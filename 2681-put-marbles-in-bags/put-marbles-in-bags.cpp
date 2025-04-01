class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if (n<=2 || n==k) return 0;
        vector<int> P(n-1, 0);
        for (int i=0; i<n-1; i++)
            P[i]=weights[i]+weights[i+1];
        
        sort(P.begin(), P.end());

        long long minP=accumulate(P.begin(), P.begin()+(k-1), 0LL), 
        maxP=accumulate(P.begin()+(n-k), P.end(), 0LL);
        
        return maxP-minP;
    }
};