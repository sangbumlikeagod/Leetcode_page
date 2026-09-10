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
    private int answer = 0;
    private int[] AvCnt(TreeNode node)
    {
        int [] ret = {node.val, 1}; 
        if (node.left != null)
        {
            int[] nxt = AvCnt(node.left);
            ret[0] += nxt[0];
            ret[1] += nxt[1];
        }
        if (node.right != null)
        {
            int[] nxt = AvCnt(node.right);
            ret[0] += nxt[0]; 
            ret[1] += nxt[1];
        }
        if (
            ret[0] / ret[1] == node.val
        )
        {
            answer++;
        }
        return ret;
    }
    public int averageOfSubtree(TreeNode root) {
        AvCnt(root);
        return answer;   
    }
}