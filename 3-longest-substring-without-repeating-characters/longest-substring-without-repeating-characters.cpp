class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int n=s.length();
        int l=0,r=0,len=0,maxlen=0;
        if(n==0)return 0;
        vector<int> freq(256,-1);
        while(r<n){
            if(freq[s[r]] != -1 && freq[s[r]] >= l){
                l = freq[s[r]] + 1;
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            freq[s[r]]=r;
            r++;
        }
        return maxlen;

    }
};