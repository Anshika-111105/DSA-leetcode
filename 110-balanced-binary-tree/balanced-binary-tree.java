/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int height(TreeNode root,boolean[] flag){
        if(root==null) return 0;

        int lh= height(root.left,flag);
        int rh = height(root.right,flag);

        if(Math.abs(lh-rh)>1) {
            flag[0] = true;
        }
        return Math.max(lh,rh)+1;
    }
    public boolean isBalanced(TreeNode root) {
        boolean[] arr = new boolean[1];
        height(root,arr);
        return (arr[0])?false:true;
    }
}