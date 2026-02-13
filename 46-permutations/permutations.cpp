class Solution {
public:
    void perms(int i,vector<vector<int>>& res,vector<int>& nums){ //res=>by reference 
        if(i==nums.size()){
            res.push_back({nums});
            return;
        }

        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]); //alteration is in the original array =>index element-ith choice
            perms(i+1,res,nums);
            swap(nums[i],nums[j]);//backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        perms(0,result,nums);
        return result;


        

    }
};