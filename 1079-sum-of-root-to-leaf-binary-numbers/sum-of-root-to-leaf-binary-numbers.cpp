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
    int DFS(TreeNode* root, int x){
        if(!root)return 0;
        x=x*2+root->val;
        if(root->left==root->right)return x;
        return DFS(root->left,x)+ DFS(root->right,x);
    }
    int sumRootToLeaf(TreeNode* root) {
        return DFS(root , 0);
    }
};