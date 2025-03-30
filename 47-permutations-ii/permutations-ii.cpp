class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,0);
        set<vector<int>>st(ans.begin(),ans.end());
        ans.clear();
        for(auto s:st){
            ans.push_back(s);
        }
        return ans;
    }
};