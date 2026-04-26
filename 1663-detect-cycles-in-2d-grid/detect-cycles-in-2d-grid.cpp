class Solution {
    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bitset<250005> visit;

        auto dfs = [&](this auto&& dfs, int r, int c, int pr, int pc) -> bool {
            visit[r * n + c] = 1;

            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k][0];
                int nc = c + dirs[k][1];
                if ((nr != pr || nc != pc) && nr >= 0 && nr < m && nc >= 0 &&
                    nc < n && grid[nr][nc] == grid[r][c] &&
                    (visit[nr * n + nc] || dfs(nr, nc, r, c)))
                    return true;
            }

            return false;
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visit[i * n + j] && dfs(i, j, -1, -1))
                    return true;

        return false;
    }
};