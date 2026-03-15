class Solution {
public:
    int countLessOrEqual(vector<vector<int>>& matrix, int median){
        int m=matrix.size(),n=matrix[0].size();
        int count=0, c=n-1;
        for(auto r=0;r<m;r++){
            while(c>=0 && matrix[r][c]>median){
                --c;
            }
            count+=(c+1);
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        int left=matrix[0][0], right=matrix[m-1][n-1];
        int ans=-1;
        while(left<=right){
            int mid=(left+right)>>1;
            if(countLessOrEqual(matrix,mid)>=k){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;

    }
};