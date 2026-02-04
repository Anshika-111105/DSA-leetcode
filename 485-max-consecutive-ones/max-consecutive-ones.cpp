class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int len=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                len++;
            }else{
                len=0;
            }
            maxlen=max(len,maxlen);
        }
        return maxlen;
    }
};