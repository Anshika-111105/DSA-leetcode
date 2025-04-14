class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int count=0;
        for(int i=0; i<n-2; i++){
            int x=arr[i];
            for(int j=i+1; j<n-1; j++){
                int y=arr[j];
                if (abs(x-y)>a) continue;
                for(int k=j+1; k<n; k++){
                    int z=arr[k];
                    if (abs(y-z)>b) continue;
                    count+=abs(abs(x-z))<=c;
                }
            }
        }
        return count;
    }
};