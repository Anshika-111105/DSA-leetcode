class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)return 0;
        int l=0,r=0,len=r-l+1;
        int maxlen=0;
        vector<int> hash(256,-1);
        while(r<n){
            if(hash[s[r]]!=-1){ //in the map
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            len=r-l+1;
            maxlen=max(len,maxlen);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
/*class solution{
public:
    int lengthOfLongestSubstring(string s){
        int n=s.length();
        int l=0,r=0,l=0, maxlen=0;
        if(n==0)return 0; //edge case
        vector<int> freq(256,-1);
        while(r<n){
            if(freq[s[r]]!=-1){
                if(freq[s[r]]>=l){
                    l=freq[s[r]]+1;
                }
            }
            len=r-l+1;
            maxlen=max(len,maxlen);
            freq[s[r]]=r;
            r++;
        }
        return
    }
}*/