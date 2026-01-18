class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int,int>> zeros;

        // Step 1: store positions of zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }

        // Step 2: mark rows and columns
        for (auto &p : zeros) {
            int r = p.first;
            int c = p.second;

            // zero entire row
            for (int j = 0; j < m; j++)
                matrix[r][j] = 0;

            // zero entire column
            for (int i = 0; i < n; i++)
                matrix[i][c] = 0;
        }
    }
};