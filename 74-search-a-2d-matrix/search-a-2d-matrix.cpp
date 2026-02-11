class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix, int target,int row){
        int n=matrix[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(target==matrix[row][mid])return true;
            else if(target>matrix[row][mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(); //no. of rows
        int n=matrix[0].size();//no of columns
        int startRow=0,endRow=m-1;
        while(startRow<=endRow){
            int mid=startRow+(endRow-startRow)/2; //to avoid Integer Overflow
            if(target>=matrix[mid][0] && target<=matrix[mid][n-1]){
                //found the row => BS on that row
                return searchRow(matrix,target,mid);
            }else if(target>=matrix[mid][n-1]){
                startRow=mid+1;
            }else{
                endRow=mid-1;
            }
        }
        return false;
  
    }
};