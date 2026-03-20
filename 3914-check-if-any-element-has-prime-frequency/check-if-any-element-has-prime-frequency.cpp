class Solution {
private:
    bool isPrime(int n){
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(const auto& n : nums){
            mp[n]++;
        }
        for(const auto& entry : mp){
            if(isPrime(entry.second)){
                return true;
            }
        }
        return false;
    }
};