/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool balanced = true;

    int dfs(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int l = dfs(node->left);
        int r = dfs(node->right);

        if (abs(l - r) > 1)
            balanced = false;

        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
    }
};