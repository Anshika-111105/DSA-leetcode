class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq; //put all in map with freq
        for(auto& n:nums){
            freq[n]++;
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > min_heap;
        for(auto& i:freq){
            min_heap.push({i.second,i.first});
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        vector<int> result;
        while(k--){
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
        
    }
};