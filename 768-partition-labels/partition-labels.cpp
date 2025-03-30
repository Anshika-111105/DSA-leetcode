class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last_occurence;
        for(int i=0;i<s.size();i++){
            last_occurence[s[i]]=i;
        }
        vector<int> res;
        int start=0,end=0;
        for(int i=0;i<s.size();i++){
            end=max(end,last_occurence[s[i]]);
            if(i==end){
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
};