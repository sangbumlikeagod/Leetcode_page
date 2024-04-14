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
// 내가 왼쪽의 자식임을 알아야함, 내가 왼쪽의 자식인데
class Solution
{
    int ans = 0;

    void search(TreeNode *root, int isRight)
    {
        if (root->left == nullptr && root->right == nullptr && !isRight)
        {
            ans += root->val;
        }
        if (root->left)
        {
            search(root->left, 0);
        }
        if (root->right)
        {
            search(root->right, 1);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        search(root, 1);
        return ans;
    }
};