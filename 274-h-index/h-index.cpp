class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend()); // Sort in descending order
        int h = 0;

        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                h = i + 1; // Update h-index if condition holds
            } else {
                break;
            }
        }

        return h;
        
    }
};