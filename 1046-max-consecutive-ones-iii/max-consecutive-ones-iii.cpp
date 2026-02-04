class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //Max Consecutive Ones III= max subarray with atmost k zeros
        int l = 0, zeros = 0, maxLen = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) zeros++;
            // shrink window until it becomes valid
            while (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }
            // valid window: zeros <= k
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;;
    }
};