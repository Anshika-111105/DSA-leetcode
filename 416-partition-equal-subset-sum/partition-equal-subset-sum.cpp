class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 
        for(int x : nums) {
            sum+= x ; 
        }
        if(sum % 2 != 0 )  return false ; 
        sum = sum / 2 ; 
        int n = nums.size() ; 
        vector<vector<bool>> dp(n , vector<bool>(sum+1 , 0)) ; 
        for(int i =0  ; i < n ; i++) {
            dp[i][0] = true ; 
        }
        if(nums[0] <= sum) dp[0][nums[0]] = true  ; 
        for(int i =1 ; i < n ; i++) {
            for(int j =1 ; j <= sum ; j++) {
                bool not_pick = dp[i-1][j] ; 
                bool pick = false ; 
                if(nums[i] <= j ) pick = dp[i-1][j - nums[i]] ; 
                dp[i][j] = pick ||not_pick;
            }
        }
        return dp[n-1][sum] ; 
        
    }
};

