class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxi = -1;
        // the longest string which is not a subsequence of other is the answer
        for (int i = 0; i < strs.size(); i++) {
            bool isSubsequence = false;
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && subseq(strs[i], strs[j])) {
                    isSubsequence = true;
                    break;
                }
            }
            if (!isSubsequence) maxi = max(maxi, (int)strs[i].length());
        }
        return maxi;
    }

    bool subseq(string a, string b) {
    int i = 0;
    for (char c : b) if (i < a.size() && a[i] == c) i++;
    return i == a.size();
    }
};