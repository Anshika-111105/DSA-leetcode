class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int bestBuy=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]>bestBuy){
                maxProfit=max(maxProfit,prices[i]-bestBuy);  //selling prices must be maximum 
            }
            bestBuy=min(bestBuy,prices[i]);   //cost price must be minimum
        }
        return maxProfit;
    }
};