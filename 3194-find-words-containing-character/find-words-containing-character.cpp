class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(words[i].find(x,0)!=string::npos){
                v.push_back(i);
            }
        }
        return v;
    }
};