class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        double d=0;
        
        for(int j=0;j<k;j++)
        d+=nums[j];
        ans=d;

        for(int i=k,j=0;i<nums.size();i++,j++)
        {
            d+=nums[i];
            d-=nums[j];
            ans = max(ans,d);
        }

        return ans/k;
    }
};