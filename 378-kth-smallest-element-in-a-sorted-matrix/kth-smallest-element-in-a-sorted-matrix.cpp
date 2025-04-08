class Solution {
public:
    int countLessEqual(vector<vector<int>>&matrix, int mid, int n){
        int count=0, row=n-1, col=0;
        while(row>=0 && col<n){
            if(matrix[row][col]<=mid){
                count+=row+1;
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0], high=matrix[n-1][n-1];
        int ans=matrix[0][0];
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=countLessEqual(matrix, mid, n);
            if(count>=k){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans; 
    }
};