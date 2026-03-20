class Solution {
private:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; (long long)i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i]))// Main diagonal: mat[i][i]
                result = max(result, nums[i][i]);

            //avoid double-counting centre cell when n is odd
            if (i != n - 1 - i) {
                if (isPrime(nums[i][n - 1 - i]))// Anti diagonal: mat[i][n-1-i]
                    result = max(result, nums[i][n - 1 - i]);
            }
        }
        return result;
    }
};