class Solution {
    public boolean isCol(char[][] board, char target, int row, int col) {
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == target && r != row) {
                return true;
            }
        }
        return false;
    }

    public boolean isRow(char[][] board, char target, int row, int col) {
        for (int c = 0; c < 9; c++) {
            if (board[row][c] == target && c != col) {
                return true;
            }
        }
        return false;
    }

    public boolean isBox(char[][] board, char target, int row, int col) {
        int sr = 3 * (row / 3);
        int sc = 3 * (col / 3);

        for (int k = 0; k < 9; k++) {
            int nextR = sr + k / 3;
            int nextC = sc + k % 3;

            if (board[nextR][nextC] == target && (nextR != row || nextC != col)) {
                return true;
            }
        }
        return false;
    }

    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue; // Skip empty cells

                if (isCol(board, board[i][j], i, j) || 
                    isRow(board, board[i][j], i, j) || 
                    isBox(board, board[i][j], i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
}