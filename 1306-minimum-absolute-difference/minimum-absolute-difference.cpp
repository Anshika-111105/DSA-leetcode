class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int min_diff=INT_MAX;
        for(int i=0;i<n-1;i++){
            int diff = arr[i+1]-arr[i];
            if(diff <min_diff){
                res.clear();
                min_diff=diff;
                res.push_back({arr[i],arr[i+1]});

            }
            else if(diff==min_diff){
                res.push_back({arr[i],arr[i+1]});
            }
        }
        return res;
    }
};
//TC: O(nlogn)