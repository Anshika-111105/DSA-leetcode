class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int len_nice_subarray = 1;
        int n = nums.size();

        int l = 0;
        int r = 1;

        while (r < n) {
            // Check the AND op of [r] and the numbers between [l, r) is avaliable
            for (int i = r - 1; i >= l; --i) {
                if (nums[r] & nums[i]) {
                    l = i + 1;
                    break;
                }
            }
            len_nice_subarray = max(len_nice_subarray, r - l + 1);

            ++r;
        }

        return len_nice_subarray;
    }
};