class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1.0; //power->0
        if(x==0)return 0.0; //base->0
        if(x==1)return 1.0; //base->1
        if(x==-1 && n%2==0) return 1.0; // (-1)^even=positive
        if(x==-1 && n%2!=0) return -1.0; //(-1)^odd=negative
        long binaryForm=n;
        if(n<=0){
            x=1/x;
            binaryForm=-binaryForm; //(3)^-5=(1/3)^5 
        }
        double answer=1;
        while(binaryForm>0){
            if(binaryForm %2==1)answer*=x;
            x*=x;
            binaryForm=binaryForm/2;
        }
        return answer;

        
    }
};