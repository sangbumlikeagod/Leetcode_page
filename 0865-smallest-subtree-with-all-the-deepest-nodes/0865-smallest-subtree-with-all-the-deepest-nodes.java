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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        Queue<TreeNode> q3 = new LinkedList<>();
        // find deepest
        HashMap<TreeNode, TreeNode> m1 = new HashMap<>();
        HashSet<TreeNode> h1 = new HashSet<>();
        HashSet<TreeNode> h2 = new HashSet<>();
        q1.add(root);
        while (true)
        {
            while (!q1.isEmpty())
            {
                TreeNode node = q1.poll();
            
                if (node.left != null)
                {
                    q2.add(node.left);
                    m1.put(node.left, node);
                }
                if (node.right != null)
                {
                    q2.add(node.right);
                    m1.put(node.right, node);
                }
                q3.add(node);
            }

            if (q2.isEmpty())
            {
                for (TreeNode node : q3)
                {
                    h1.add(node);
                }
                break;
            }
            else
            {
                q1 = q2;
                q2 = new LinkedList<>();
                q3 = new LinkedList<>();
            }
        }
        while (h1.size() > 1)
        {

            for (TreeNode node : h1)
            {
                h2.add(m1.get(node));
            }
            h1 = h2;
            h2 = new HashSet<>();
        }
        List<TreeNode> answer = h1.stream().collect(
            Collectors.toList()
        );
        return answer.get(0);


    }
}