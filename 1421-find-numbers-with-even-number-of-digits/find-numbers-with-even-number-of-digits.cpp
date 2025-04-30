class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result=0;
        for(auto number:nums)
            result+=int(floor(log10(number))+1)%2==0;
        return result;
    }
};