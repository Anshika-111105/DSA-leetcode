class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        // Start from top-right corner
        int row = 0, col = n - 1;

        while(row < m && col >= 0){
            if(matrix[row][col] == target){
                return true;
            } else if(matrix[row][col] > target){
                // Move left
                col--;
            } else {
                // Move down
                row++;
            }
        }
        return false;
    }
}