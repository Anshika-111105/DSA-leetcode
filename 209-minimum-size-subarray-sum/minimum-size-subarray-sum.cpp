class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int len=INT_MAX;
        int left=0;
        for(int right = 0; right< nums.size(); right++){

            sum += nums[right];

            while(sum >= target){
                len = min(len, right-left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return len > 1000000 ? 0 : len;

    }
};