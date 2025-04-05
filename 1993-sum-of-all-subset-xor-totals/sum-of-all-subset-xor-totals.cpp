class Solution {
public:
void subset(vector<int>& nums,int index,vector<int>& ans,int x,int &sum){
    if(index>=nums.size())
    {
        for(int val:ans){
            x^=val;
        }
        sum+=x;
        return;
    }
    ans.push_back(nums[index]);
    subset(nums,index+1,ans,x,sum);
    ans.pop_back();
    subset(nums,index+1,ans,x,sum);
}
    int subsetXORSum(vector<int>& nums) {
        vector<int>ans;
        int x=0;
        int sum=0;
        subset(nums,0,ans,x,sum);
        return sum;
    }
};