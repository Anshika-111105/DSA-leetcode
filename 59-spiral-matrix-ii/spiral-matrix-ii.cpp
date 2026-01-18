class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n,vector<int>(n));
        vector<vector<bool>> con(n,vector<bool>(n, false));
        int no = 1;
        int i = 0;
        int j = 0;
        while(no <= n*n)
        {
            while((i < n && j < n) && con[i][j] == false)
            {
                vec[i][j] = no;
                no++;
                con[i][j] = true;
                j++;
            }
            i++;
            j--;
            while((i < n && j < n) && con[i][j] == false)
            {
                vec[i][j] = no;
                no++;
                con[i][j] = true;
                i++;
            }
            j--;
            i--;
            while((i < n && j >= 0) && con[i][j] == false)
            {
                vec[i][j] = no;
                no++;
                con[i][j] = true;
                j--;
            }
            i--;
            j++;
            while((i >= 0 && j < n) && con[i][j] == false)
            {
                vec[i][j] = no;
                no++;
                con[i][j] = true;
                i--;
            }
            i++;
            j++;
        }
        return vec;
    }
};