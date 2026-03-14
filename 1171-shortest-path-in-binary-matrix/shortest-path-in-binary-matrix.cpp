class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Step 1: Handle edge cases
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        // Step 2: Initialize BFS queue and visited matrix
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        vis[0][0] = 1;
        q.push({1, {0, 0}});  // {distance, {row, col}}
        
        // Step 3: Define 8 directions (king-like movement)
        int delrow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delcol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        // Step 4: BFS traversal
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            // Step 5: Check if we reached destination
            if (row == n - 1 && col == n - 1)
                return dis;
            
            // Step 6: Explore all 8 neighbors
            for (int i = 0; i < 8; i++) {
                int newr = row + delrow[i];
                int newc = col + delcol[i];
                
                // Step 7: Validate neighbor
                if (newr >= 0 && newc >= 0 && newr < n && newc < n &&
                    grid[newr][newc] == 0 && vis[newr][newc] == 0) {
                    
                    // Step 8: Add valid neighbor to queue
                    vis[newr][newc] = 1;
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }
        // Step 9: No path found
        return -1;
    }
};