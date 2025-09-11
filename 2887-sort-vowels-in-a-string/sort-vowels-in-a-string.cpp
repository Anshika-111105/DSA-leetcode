class Solution {
public:
    bool isVowel(char c){
        vector<char> vowels = {'A','E','I','O','U','a','e','i','o', 'u'};
        for(int i=0; i<vowels.size();i++){
            if(c==vowels[i]){
                return true;
            }
        }
        return false;
    }

    string sortVowels(string s) {
    
       int sLen = s.size();
       vector<int> occurence(100);
    //    cout<<occurence[80];
       for(int i=0; i<sLen; i++){
            if(isVowel(s[i])){
                occurence[s[i]-'A']++;         
            }
        }

        string ans = "";
        for(int i=0; i<sLen; i++){
            if(isVowel(s[i])){
                for(int i=0;i<100;i++){
                    if(occurence[i]>0){
                        char c = 'A'+ i;
                        ans+= c;
                        occurence[i]--;
                        break;
                    }
                }
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};