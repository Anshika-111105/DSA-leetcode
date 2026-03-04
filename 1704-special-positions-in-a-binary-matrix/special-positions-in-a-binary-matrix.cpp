class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int i = mat.size();
        int j = mat[0].size();
        vector<long long> row(i,0),col(j,0);
        for(int k=0; k<i; k++){
            long long sum=0;
            for(int l=0; l<j; l++){
                sum+=mat[k][l];
            }
            row[k]=sum;
        }
        for(int k=0; k<j; k++){
            long long sum=0;
            for(int l=0; l<i; l++){
                sum+=mat[l][k];
            }
            col[k]=sum;
        }
        int count=0;
        for(int r=0; r<i; r++){
            for(int c=0; c<j; c++){
                if(mat[r][c]){
                    if(row[r]==1 && col[c]==1) count++;
                }
            }
        }
        return count;
    }
};