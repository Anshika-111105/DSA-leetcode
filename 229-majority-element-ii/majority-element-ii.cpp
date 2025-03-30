class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;
        vector<int> result;
        int n = nums.size() / 3;

        for (int num : nums) countMap[num]++;
        for (auto& [num, count] : countMap) if (count > n) result.push_back(num);
        
        return result;
    }
};