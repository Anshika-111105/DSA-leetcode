class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace invalid numbers
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = n + 1;
            }
        }

        // Step 2: Mark presence
        for(int i = 0; i < n; i++){
            int element = abs(nums[i]);

            if(element == n + 1){
                continue;
            }

            int seat = element - 1;

            if(nums[seat] > 0){
                nums[seat] = -nums[seat];
            }
        }

        // Step 3: Find first missing
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }

        return n + 1;
    }
};