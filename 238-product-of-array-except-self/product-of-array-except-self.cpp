class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        vector<int> result(n);
        // Fill prefix array
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Fill suffix array
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Calculate the result
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;

    }
};