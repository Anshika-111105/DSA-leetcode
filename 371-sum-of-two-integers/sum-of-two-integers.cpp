class Solution {
public:
    int getSum(int a, int b) {
        int sum=a^b;  //XOR (^) gives the sum of bits without carry
        int carry=(a&b)<<1; //AND (&) identifies positions where carry is generated , Left shift (<<1) propagates the carry to the next bit position
        if(carry) return getSum(sum,carry);  
        return sum;
    }
};