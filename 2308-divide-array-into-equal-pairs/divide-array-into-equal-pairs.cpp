class Solution {
public:
    static bool divideArray(vector<int>& nums) {
        bitset<501> parity=0;
        for(int x: nums) parity.flip(x);
        return (parity.count())?0:1;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();