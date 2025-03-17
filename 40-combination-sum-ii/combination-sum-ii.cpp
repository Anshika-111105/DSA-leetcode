class Solution {
public:
    void generateCombinations(int idx, int target, int sum, vector<int>& candidates, vector<int>& ans, vector<vector<int>>& sol) {
        if (sum == target) {
            sol.push_back(ans);
            return;
        }
        if (sum > target || idx >= candidates.size()) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            
            ans.push_back(candidates[i]);
            generateCombinations(i + 1, target, sum + candidates[i], candidates, ans, sol);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        generateCombinations(0, target, 0, candidates, ans, sol);
        return sol;
    }
};