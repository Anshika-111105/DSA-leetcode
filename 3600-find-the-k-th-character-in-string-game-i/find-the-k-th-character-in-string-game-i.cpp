class Solution {
public:
    char kthCharacter(int k) {
        int jump = 0, num = k;
        while(num > 1){
            int range = log2(num);
            int mid = (1<<range);
            if(num == mid){
                range--;
                mid = (1<<range);
            }
            num -= mid;
            jump++;
        }
        return (char)('a'+jump);
    }
};