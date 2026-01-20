class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int> result(n);
        int prefix=1, suffix=1;
        for(int i=0;i<n;i++){
            result[i]=prefix;
            prefix*=nums[i];
        }
        for(auto j=n-1;j>=0;j--){
            result[j]*=suffix;
            suffix*=nums[j];
        }
        return result;

    }
};