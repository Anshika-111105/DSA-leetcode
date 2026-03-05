class Solution {
public:
    int minOperations(string& s) {
        //Use the fact op0+op1=n
        int n=s.size(), op0=0;
        for(int i=0; i<n; i++){
            op0+=(i&1)==(s[i]&1);
        }
        return min(op0, n-op0);
    }
};