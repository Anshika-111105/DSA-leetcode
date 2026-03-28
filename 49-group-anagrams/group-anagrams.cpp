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
/*
Approach :
Using an Unordered Map: We utilize an unordered map to store the sorted version of each string (anagram) as the key and the index of the corresponding group in the answer vector as the value. This allows us to quickly check if an anagram group already exists.

Iterating Through the Input Strings: We iterate through each string in the input vector 'strs'.

Sorting Strings: For each string, we sort its characters alphabetically. This ensures that anagrams will have the same sorted representation.

Grouping Anagrams: We check if the sorted string exists in the unordered map. If it does, we add the current string to the corresponding group in the answer vector. If not, we create a new group and store its index in the unordered map.

Returning the Answer: Once all strings have been processed, we return the answer vector containing the grouped anagrams.
*/