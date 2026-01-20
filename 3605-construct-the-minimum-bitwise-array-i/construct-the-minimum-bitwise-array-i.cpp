class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto& num:nums){
            if(num & 1){
                auto z =((num+1)& ~num)>>1;
                ans.push_back(num & ~z);
            }else{
                ans.push_back(-1);
            }
        }
    return ans;  
    }
};