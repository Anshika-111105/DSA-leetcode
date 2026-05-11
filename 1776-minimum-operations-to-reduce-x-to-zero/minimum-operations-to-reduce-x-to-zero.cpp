class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum=0;
        for(auto& n:nums){
            totalSum+=n;
        }
        int n = nums.size();
        int target=totalSum-x;
        if(target < 0)return -1;
        if(target == 0)return nums.size();
        int left = 0 , currSum = 0 , maxlen = -1;
        for(int right = 0; right < nums.size(); right++){
            currSum += nums[right];
            while(currSum > target){
                currSum-=nums[left++];
            }
            if(currSum == target) {
                maxlen = max(maxlen, right - left + 1);
            }
        }
        if(maxlen == -1) return -1;

        return n - maxlen;

    }
    
};