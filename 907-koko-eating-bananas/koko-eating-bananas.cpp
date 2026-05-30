class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0;i < n;i++){
            maxi = max(piles[i],maxi);
        }
        return maxi;
    }
    double eating_Hourly(vector<int>& piles , int value){
        double total_Hours = 0;
        int n = piles.size();
        for(int i = 0;i < n;i++){
            total_Hours += ceil((double)piles[i]/(double)value); 
        }
        return total_Hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0 , high = findMax(piles);
        int answer = INT_MAX;
        while(low <= high){
            int mid = low+(high-low)/2;
            double totalHours = eating_Hourly(piles,mid);
            if(totalHours <= h){
                answer = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return answer;
    }
};