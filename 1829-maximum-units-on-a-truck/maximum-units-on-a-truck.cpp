class Solution {
public:
    static bool comp(vector<int>& box1, vector<int>& box2){
        return box1[1] > box2[1];  
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        int remSize=truckSize;
        int totUnits = 0;
        sort(boxTypes.begin(), boxTypes.end(), comp);// Sort by units per box in descending order
        for(int i=0;i<n;i++){
            if(remSize==0) break;
            if(boxTypes[i][0]<=remSize){
                // Take all boxes of this type
                remSize-=boxTypes[i][0];
                totUnits+=boxTypes[i][0]*boxTypes[i][1];
            }else {
                // Take only the remaining boxes we can fit
                totUnits+=remSize*boxTypes[i][1];
                remSize=0;  // Truck is full
            }
        }
        return totUnits;
    }
};