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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int count =0; 
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            count++;

            if(current->left != nullptr){
                q.push(current->left);
            }

            if(current->right != nullptr){
                q.push(current->right);
            }
        }

        return count;
    }
};