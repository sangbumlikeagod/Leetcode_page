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
    private Integer answer = 0;

    private void getNext(TreeNode node, Integer val)
    {
        val |= node.val;
        int next = (val << 1);
        if (node.left != null)
        {
            getNext(node.left, next);
        }
        if (node.right != null)
        {
            getNext(node.right, next);
        }
        if (node.left == null && node.right == null)
        {
            answer += val;
        }
    }

    public int sumRootToLeaf(TreeNode root) {
        getNext(root, 0);
        return answer;    
    }
}