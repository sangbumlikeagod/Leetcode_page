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
public:
    int root1L[201];
    int root1Idx = 0;
    int root2Idx = 0;
    bool dfs(TreeNode* root, int go){
        if (root -> left == nullptr && root -> right == nullptr){
            if (go == 1){
                root1L[root1Idx++] = root -> val;
            }
            else {

                if (root -> val != root1L[root2Idx++]) {
                    cout << "false" << '\t';
                    return false;
                } 
                else {
                    cout << "true" << '\t';
                    return true;
                }
            }
        }
        if (root -> left != nullptr) {
            bool result = dfs(root -> left, go);
            if (!result) { return false; }
        }
        if (root -> right){
            bool result = dfs(root -> right, go);
            if (!result) { return false; }
        }
        return true;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        bool ans;
        ans = dfs(root1, 1);
        return (dfs(root2, 2) && root2Idx == root1Idx) ;
    }
};