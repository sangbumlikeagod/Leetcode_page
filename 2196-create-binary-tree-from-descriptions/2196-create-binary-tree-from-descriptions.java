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

    private int hashId = 0;
    private HashMap<Integer, Integer> hmap = new HashMap<>();

    public TreeNode createBinaryTree(int[][] descriptions) {
        int n = descriptions.length;

        TreeNode[] nodes = new TreeNode[10001];
        int[] parents = new int[100001];



        for (int i = 0; i < n; i++)
        {

            // hmap.put(hashId, descriptions[i][1]);
            if (hmap.get(descriptions[i][0]) == null)
            {
                hmap.put(descriptions[i][0], hashId++);
                nodes[hashId - 1] = new TreeNode(descriptions[i][0]);
            }
            if (hmap.get(descriptions[i][1]) == null)
            {
                hmap.put(descriptions[i][1], hashId++);
                nodes[hashId - 1] = new TreeNode(descriptions[i][1]);
            }

            int parentId = hmap.get(descriptions[i][0]);
            int childId = hmap.get(descriptions[i][1]);
            if (descriptions[i][2] == 1)
            {
                parents[childId]++;
                nodes[parentId].left = nodes[childId];
            }
            else
            {
                parents[childId]++;
                nodes[parentId].right = nodes[childId];
            }
        }

        for (int i = 0; i < 10001; i++)
        {
            if (
                nodes[i] != null && 
                parents[i] ==0
            )   
            {
                return nodes[i];
            }
        }
        return null;

    }
}