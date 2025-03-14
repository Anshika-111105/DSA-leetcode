class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        int temp = 1;
        for(int i = 0; i < n; i++){
            matrix.push_back({});
            for(int j = 0; j < n; j++){
                matrix[i].push_back(temp);
                temp++;
            }
        }

        int top = 0, left = 0;
        int bottom = n - 1, right = n - 1;
        int idx = 1;
        while (top <= bottom && left <= right) {

            // right
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = idx;
                idx++;
            }
            top++;
            
            // down
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = idx;
                idx++;
            }
            right--;
            
            // left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = idx;
                    idx++;
                }
                bottom--;
            }
            
            // up
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = idx;
                    idx++;
                }
                left++;
            }
        }
        return matrix;
    }
};
