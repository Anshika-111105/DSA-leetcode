class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr{0};
        for(int i=1;i<=n;i++){
            arr.push_back(arr[i&(i-1)]+1);
        }
        return arr;
    }
};