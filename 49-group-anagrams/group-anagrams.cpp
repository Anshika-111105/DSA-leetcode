class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mp;
        vector<vector<string>> answer;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(word.begin(),word.end());
            if(mp.find(word)!=mp.end()){
                answer[mp[word]].push_back(strs[i]);
            }else{
                mp[word]=answer.size();
                answer.push_back({strs[i]});
            }
        }
        return answer;
    }
};