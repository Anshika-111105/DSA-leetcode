class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int m=grid.size(), n=grid[0].size(), N=m*n;
        vector<int> val(N,0);
        int r=grid[0][0]%x,i=0;
        for (const auto& row : grid) {
            for (int num : row) {
                auto [q, rr] = div(num, x);
                if (rr != r)
                    return -1;
                val[i++]=q;
            }
        }
        sort(val.begin(), val.end());
        int med=(N&1)?val[N/2] : (val[N/2-1] + val[N/2])/2;
        int op = 0;
        for (int num : val)
            op+=abs(num-med);

        return op;
    }
};