class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); //nlogn
        int n=nums.size();
        int i=0,maxlen=1;
        for(int j=0;j<n;j++){
            while((long long)nums[j]>(long long)nums[i]*k){
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return n-maxlen;

    }
};