class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        if (mini < k) return -1; 
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > k) {
                count++;
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) 
                    i++;
            }
        }
        return count;
    }
};