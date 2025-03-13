class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size(),m=(l+r)/2;
        if(r==1 && nums[r-1]!=target)
        return -1;
        while(l<=r)
        {
            if(target==nums[m])
            return m;
            if(target>nums[m])
            l=m+1;
            if(target<nums[m])
            r=m-1;
            m=(l+r)/2;
        }
        return -1;
    }
};