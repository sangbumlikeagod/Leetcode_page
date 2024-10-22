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
class Solution
{
    vector<long long> leap;
    void dfs(int level, TreeNode *root)
    {
        if (leap.size() <= level)
        {
            leap.push_back(0);
        }
        leap[level] += root->val;
        if (root->left)
        {
            dfs(level + 1, root->left);
        }
        if (root->right)
        {
            dfs(level + 1, root->right);
        }
    }

public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        dfs(0, root);
        sort(leap.begin(), leap.end());
        return leap.size() >= k ? leap[leap.size() - k] : -1;
    }
};