class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // Find the minimum element in the array
        int mn = *min_element(nums1.begin(), nums1.end());
        
        // If the minimum element is odd, we can make all elements odd
        if (mn % 2 == 1) {
            return true;
        } else {
            // If the minimum is even, all elements MUST already be even
            for (int i = 0; i < nums1.size(); i++) {
                if (nums1[i] % 2 == 1) {
                    return false; // Found an odd number, impossible to convert
                }
            }
        }
        return true;
    }
};