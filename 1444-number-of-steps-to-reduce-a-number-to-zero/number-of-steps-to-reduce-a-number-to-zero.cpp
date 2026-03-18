class Solution {
private:
    int helper(int num,int steps){
        if(num==0)return steps;
        if(num%2==0){
            return helper(num/2,steps+1); //current number is even, you have to divide it by 2
        }
        return helper(num-1,steps+1); //otherwise, you have to subtract 1
    }
public:
    int numberOfSteps(int num) {
        return helper(num,0);
    }
};