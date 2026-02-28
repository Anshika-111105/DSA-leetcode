class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1000000007;
        long long ans = 0;
        int bits = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                bits++;
            }
            ans = ((ans << bits) % mod + i) % mod;
        }
        return ans;
    }
};