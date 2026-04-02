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
    int Maxsearch(vector<int>& nums,int left,int right){
        int maxIdx = left;
        for(int i = left; i <= right; i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }
        return maxIdx;

    }
    TreeNode* helper(vector<int>& nums,int left,int right){
        if (left > right) return nullptr; //base case
        int maxvalue_index = Maxsearch(nums, left, right); //search for current subarray range
        TreeNode* root=new TreeNode(nums[maxvalue_index]);
        root->left = helper(nums, left, maxvalue_index - 1);
        root->right = helper(nums, maxvalue_index + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};