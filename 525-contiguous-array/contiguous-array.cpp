class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),sum=0,res=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
            sum+=nums[i];
            if(sum==0){
                res=i+1;
            }
            if(mp.find(sum)!=mp.end()){
                res=max(res,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return res;

    }
};