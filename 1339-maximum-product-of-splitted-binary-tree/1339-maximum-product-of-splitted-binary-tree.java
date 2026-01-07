/**
    idx ++;
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *  
 idx++;   TreeNode right;
 *     TreeNode righ;
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
    int MODULO = (int) 1e9 + 7;
    int idx = 0;
    int[] value = new int[50001];

    public int dfs(TreeNode node){
        int self = node.val;
        int me = idx;
        
        if (node.left != null)
        {
            idx ++;
            self += dfs(node.left);
        }
        if (node.right != null)
        {
            idx++;
            self += dfs(node.right);
        }
        value[me] = self;
        return self;
    }
    public int maxProduct(TreeNode root) {
        dfs(root);
        int total = value[0];
        long answer = 0;
        for (int i = 1; value[i] != 0; i++)
        {
            long val = value[i];
            val *= total - value[i];
            answer = Math.max(answer,  val);
        }
        return (int) (answer % MODULO);
    }
}