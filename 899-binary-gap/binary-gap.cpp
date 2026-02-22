class Solution {
public:
    int binaryGap(int n) {
        int longest=0;
        bool one_found=false;
        int current=0;
        while(n){
            if(n&1){
                longest=max(longest,current);
                one_found=true;
                current=1;
            }else{
                if(one_found)++current;
            }
            n>>=1;
        }
        return longest;
    }
};