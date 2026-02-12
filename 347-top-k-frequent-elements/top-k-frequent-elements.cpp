class Solution {
public:
    static bool check(pair<int,int>a, pair<int,int>b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq; //put all in map with freq
        for(auto& n:nums){
            freq[n]++;
        }
        vector<pair<int,int>> answer;
        for(auto& x:freq){
            answer.push_back({x.first,x.second}); //add pair wise num,count
        }
        sort(answer.begin(),answer.end(),check); //sort according to count
        vector<int>real;
        for(int i=0;i<k;i++){ //i to k-1 are answers return
            real.push_back(answer[i].first);
        }
        return real;
        
    }
};