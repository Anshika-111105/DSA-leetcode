class Solution {
private:
    bool isPrime(int n){
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++){
            if (n % i == 0) return false;
        }   
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int prime_count=0,i=0,count;
        while(left<=right){
            count=__builtin_popcount(left);
            left++;
            if(isPrime(count)){
                prime_count++;
            }
        }
        return prime_count;

    }
};