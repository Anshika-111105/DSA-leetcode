class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0, streak=0;
        for(auto x: nums){
            if(x==0){
                streak++;
                count=count+streak;
            }else{
                streak=0;
            }
            
        }
        return count;
    }
};