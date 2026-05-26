class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int Maxsum=0;
        int result=0;
        for(auto i=0;i<k;i++){
            Maxsum+=cardPoints[i];
        }
        result=Maxsum;
        for(int i=k-1;i>=0;i--){
            result-=cardPoints[i];
            result+=cardPoints[n-k+i];
            Maxsum=max(Maxsum,result);
        }
        
        return Maxsum;

    }
};