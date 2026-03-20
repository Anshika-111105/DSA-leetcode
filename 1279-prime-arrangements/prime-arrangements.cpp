class Solution {
private:
    long long permutation(int count,int MOD){
        long long ans=1;
        for(int i=2;i<=count;i++){
            ans=(ans*i)%MOD;
        }
        return ans;
    }
public:
    int numPrimeArrangements(int n) {
        int MOD= 1e9 + 7,count=0;
        for(int i=2;i<=n;i++){
            bool isPrime=true;
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0){
                    isPrime=false;
                    break;
                }
            }
            if(isPrime){
                count++;
            }
        }
        return (permutation(count,MOD)*permutation(n-count,MOD))%MOD;


    }
};