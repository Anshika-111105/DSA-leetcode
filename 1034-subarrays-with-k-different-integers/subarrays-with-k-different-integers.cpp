class Solution {
public:
    // Helper function to count subarrays with AT MOST k distinct elements
    int atMost(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0, cnt = 0;
        
        for(int right = 0; right < n; right++){
            // Updating the frequency
            freq[nums[right]]++;
            
            // If window has more than k distinct elements, shrink from left
            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            
            // Count the valid subarrays ending at 'right'
            cnt += right - left + 1;
        }           
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly K = atMost(K) - atMost(K - 1)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};