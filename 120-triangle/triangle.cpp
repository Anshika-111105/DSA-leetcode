class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minimumPathSum(triangle.size());
        for(int i=0; i<triangle.size(); i++) minimumPathSum[i] = triangle[triangle.size()-1][i];
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                minimumPathSum[j] = min(minimumPathSum[j], minimumPathSum[j+1]) + triangle[i][j];
            }
        }
        return minimumPathSum[0];
    }
};