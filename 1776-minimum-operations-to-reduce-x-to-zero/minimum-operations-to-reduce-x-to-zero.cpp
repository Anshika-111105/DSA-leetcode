class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int totalSum = 0;

        for(int num : nums) {
            totalSum += num;
        }

        int target = totalSum - x;

        // Impossible case
        if(target < 0) return -1;

        // Remove all elements
        if(target == 0) return nums.size();

        int left = 0;
        int currentSum = 0;
        int maxLen = -1;

        for(int right = 0; right < nums.size(); right++) {

            currentSum += nums[right];

            // Shrink window if sum exceeds target
            while(currentSum > target) {
                currentSum -= nums[left];
                left++;
            }

            // Valid subarray found
            if(currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // No valid subarray
        if(maxLen == -1) return -1;

        return nums.size() - maxLen;
    }
};