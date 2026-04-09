class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        bool flag=0; //track the direction at current level
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                int idx = flag ? (size - i - 1) : i;
                level[idx]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);

            }
            flag=!flag;
            ans.push_back(level);
        }
        return ans;

        
    }
};