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
    int maxVal = 0;
public:
    void dfs(TreeNode* node, int maxSofar, int minSofar){
        if(node -> left){
            maxVal = max(abs(node -> left -> val - maxSofar), maxVal);
            maxVal = max(abs(node -> left -> val - minSofar), maxVal);
            dfs(node -> left, max(maxSofar, node -> left -> val), min(minSofar, node -> left -> val));
        }
        if (node -> right){
            maxVal = max(abs(node -> right -> val - maxSofar), maxVal);
            maxVal = max(abs(node -> right -> val - minSofar), maxVal);
            dfs(node -> right, max(maxSofar, node -> right -> val), min(minSofar, node -> right -> val));
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root -> val, root -> val);
        return maxVal;
    }
};