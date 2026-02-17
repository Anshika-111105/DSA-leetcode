class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i = 0;
        while (i < n) {
            if (nums[i] <= 0 || nums[i] > n ||
                nums[i] == i + 1 ||
                nums[i] == nums[nums[i] - 1]) {
                i++;
            } else {
                swap(nums, i, nums[i] - 1);
            }
        }
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
