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
    private Integer DFS(TreeNode node) {
        int depth = 0;
        // -1 리턴이면에러
        if (node.left != null)
        {
            Integer tst = DFS(node.left);
            if (tst == -1)
            {
                return -1;
            }
            depth = tst;
        }
        if (node.right != null)
        {
            Integer tst = DFS(node.right);
            if (tst == -1)
            {
                return -1;
            }
            if (Math.abs(depth - tst) > 1) return -1;
            depth = Math.max(depth, tst);
        }
        else
        {
            if (depth > 1) return -1;
        }
        return depth + 1;
    }

    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        return DFS(root) != -1;
    }
}