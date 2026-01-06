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

    private void swapTwoQ(Queue<TreeNode> one, Queue<TreeNode> two)
    {
        Queue<TreeNode> three = one;
        one = two;
        two = three;
    }
    public int maxLevelSum(TreeNode root) {
        int answer = 0, answerVal = Integer.MIN_VALUE;

        Queue<TreeNode> q = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q.add(root);

        for (int i = 1; !q.isEmpty(); i++)
            {
                int levelSum = 0;
                while (!q.isEmpty())
                    {
                        TreeNode newNode = q.poll();
                        levelSum += newNode.val;
                        // System.out.print(newNode.val + " ");
                        if (newNode.left != null)
                        {
                            q2.add(newNode.left);
                        }
                        if (newNode.right != null)
                        {
                            q2.add(newNode.right);
                        }
                    }
                if (answerVal < levelSum)
                {
                    answer = i;
                    answerVal = levelSum;
                }
                Queue<TreeNode> three = q;
                q = q2;
                q2 = three;
                
                // swapTwoQ(q, q2);
                // System.out.println("\n"+ q2.size() + "\n");
                
            }

        return answer;
    }
}