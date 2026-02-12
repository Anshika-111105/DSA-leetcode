class Solution {
public:
    static bool check(pair<int,int>a, pair<int,int>b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(auto& n:nums){
            freq[n]++;
        }
        vector<pair<int,int>> answer;
        for(auto& x:freq){
            answer.push_back({x.first,x.second});
        }
        sort(answer.begin(),answer.end(),check);
        vector<int>real;
        for(int i=0;i<k;i++){
            real.push_back(answer[i].first);
        }
        return real;
        
    }
};