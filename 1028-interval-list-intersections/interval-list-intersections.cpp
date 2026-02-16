#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                             vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> result;

        while (i < A.size() && j < B.size()) {
            int a_start = A[i][0], a_end = A[i][1];
            int b_start = B[j][0], b_end = B[j][1];

            // Criss-cross lock (overlap exists)
            if (a_start <= b_end && b_start <= a_end) {
                result.push_back({
                    max(a_start, b_start),
                    min(a_end, b_end)
                });
            }

            // Move the pointer that ends first
            if (a_end <= b_end) {
                i++;   // Exhausted interval in A
            } else {
                j++;   // Exhausted interval in B
            }
        }

        return result;
    }
};
