class Solution {
public:
    long long minSumSquareDiff(
        vector<int>& nums1,
        vector<int>& nums2,
        int k1,
        int k2
    ) {
        int n = nums1.size();
        vector<int> diff(n);
        long long k = (long long)k1 + k2;
        long long total = 0;
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxDiff = max(maxDiff, diff[i]);
        }

        if (total <= k) return 0;

        int left = 0, right = maxDiff;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long operations = 0;

            for (int d : diff) {
                operations += max(0, d - mid);
            }

            if (operations <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int threshold = left;
        long long remaining = k;

        for (int d : diff) {
            remaining -= max(0, d - threshold);
        }

        long long result = 0;

        for (int d : diff) {
            d = min(d, threshold);

            if (d == threshold && remaining > 0) {
                d--;
                remaining--;
            }

            result += 1LL * d * d;
        }

        return result;
    }
};