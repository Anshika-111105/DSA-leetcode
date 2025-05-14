class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
		    for (int j = 0; j < board[0].length; j++) {
                // To explore all starting nodes
				if (wordExist(board, word, 0, i, j)) {
					return true;
				}
			}
		}
		return false;
	}

	private static boolean wordExist(char[][] board, String word, int n, int row, int col) {
		if (n == word.length()) {
			return true;
		}

		if (row >= 0 && row < board.length && col >= 0 && col < board[0].length && board[row][col] == word.charAt(n)) {
			board[row][col] = '.'; // visited
			boolean isExist = (wordExist(board, word, n + 1, row - 1, col)
					|| wordExist(board, word, n + 1, row + 1, col) || wordExist(board, word, n + 1, row, col - 1)
					|| wordExist(board, word, n + 1, row, col + 1));
			if (!isExist) {
				board[row][col] = word.charAt(n);
			}
			return isExist;
		}
		return false;
	
    }
}