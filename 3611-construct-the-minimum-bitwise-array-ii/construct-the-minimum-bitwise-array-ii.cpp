class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size(),a=0;
        vector<int> answer;
        for(auto& num:nums){
            if(num!=2){
                a = num-((num+1)&(-num-1))/2;
                answer.push_back(a);
            }else{
                answer.push_back(-1);
            }
        }
        return answer;
    }
};