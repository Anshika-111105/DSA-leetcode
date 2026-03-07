class Solution {
public:
    static int minFlips(string& s) {
        const int n=s.size();
        int cnt0=0, cnt1=0;
        bool flip=0;
        for (int i=0; i<n; i++, flip=!flip) { // flip 
            cnt1+=(s[i]-'0'==flip);       // accumulate prefix sum
        }
        cnt0=n-cnt1;
        int ans=min(cnt0, cnt1);
        
        if ((n&1)==0) return ans;
        int  p1=s[0]=='0', p0=1-p1;
        flip=1;
        for (int i=1; i<n; i++, flip=!flip) {
            // Prefix cost is swapped due to odd length shift
            p1+=(s[i]-'0'==flip);
            p0=(i+1)-p1; 
            const int s0=cnt0-p0;
            const int s1=cnt1-p1;
            
            // New cost = (Suffix Pattern X) + (Prefix Pattern NOT X)
            ans=min(ans, min(s0+p1, s1+p0));
        }
        return ans;
    }
};