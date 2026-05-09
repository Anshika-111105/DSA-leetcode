class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total = 0;

        for(int num : nums) {
            total += num;
        }

        int target = total - x;

        // Impossible case
        if(target < 0) return -1;

        // Need to remove everything
        if(target == 0) return nums.size();

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for(int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            // Shrink window
            while(sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found target
            if(sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // No valid subarray
        if(maxLen == -1) return -1;

        return nums.size() - maxLen;
    }
};