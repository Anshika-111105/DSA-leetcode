class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int>high(n,1),low(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])high[i]=high[i-1]+1;
            else high[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1])low[i]=low[i+1]+1;
            else low[i]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(high[i]>1 && low[i]>1){
                ans=max(ans,high[i]+low[i]-1);
            }
        }
        return ans;
    }
};





/*class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        //int answer = 0;
        int left,right,length=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                left=i;
                right=i;
                while(left>0 && arr[left]>arr[left-1]){
                    left--;
                }
                while(right<n && arr[right+1]<arr[right]){
                    right++;
                }
                length=max(length,left+right+1);
            }
        }
        return length;
    }
};*/