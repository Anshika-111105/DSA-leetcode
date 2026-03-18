class Solution {
    bool solve(int i, int j, int n, vector<vector<char>>& board, string &word, vector<vector<int>> &mark){
        if(n==word.size()){
            return 1;
        } 
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[n] || mark[i][j]==1) return 0;
        mark[i][j] = 1;
        bool ans = solve(i+1, j, n+1, board, word,mark) || solve(i-1, j, n+1, board, word, mark) || solve(i, j+1, n+1, board, word, mark) || solve(i, j-1, n+1, board, word, mark);
        mark[i][j] = 0;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>mark(board.size(), vector<int>(board[0].size(), 0));
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(solve(i, j, 0, board, word, mark)) return 1;
            }
        }
        return 0;
    }
};