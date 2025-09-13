class Solution {
public:
    int maxFreqSum(string s) {
        int fq[26]={0};

        for(auto ch:s){
            fq[ch-'a']++;
        }
        int mx_v=0; //mx_vowel
        int mx_c=0; //mx_conso

        for(int i=0;i<26;i++)
        {
            char c ='a'+i;
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                mx_v=max(mx_v,fq[i]);
            }else{
                mx_c=max(mx_c,fq[i]);
            }
        }

        return mx_v+mx_c;
    }
};