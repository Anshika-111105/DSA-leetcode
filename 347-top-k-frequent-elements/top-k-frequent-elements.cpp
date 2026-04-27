class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency
        for(int x : nums){
            freq[x]++;
        }

        // Step 2: Min heap (freq, element)
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > min_heap;

        // Step 3: Keep only top k elements
        for(auto &it : freq){
            min_heap.push({it.second, it.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }

        // Step 4: Extract result
        vector<int> ans;
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return ans;
    }
};