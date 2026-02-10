class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int r=nums[0];
        for(int i=1,i_max=r,i_min=r;i<n;i++){
            if(nums[i]<0){
                swap(i_max,i_min);
            }
            i_max=max(nums[i],i_max*nums[i]);
            i_min=min(nums[i],i_min*nums[i]);
            r=max(r,i_max);
        }
        return r;
    }
};