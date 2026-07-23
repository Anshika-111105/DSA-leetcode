class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2)return n ;
        int answer = 0;
        for(auto num : nums){
            answer |= num;
        }

        return answer + 1;
    }
};