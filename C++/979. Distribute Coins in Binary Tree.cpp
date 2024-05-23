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
    int ans = 0;

public:
    int recur(TreeNode *root)
    {
        int left = 0;
        int right = 0;
        int tmp = 0;

        if (root->left)
        {
            left = recur(root->left);
        }
        if (root->right)
        {
            right = recur(root->right);
        }
        if (left * right >= 0)
        {
            ans += abs(left + right);
        }
        else
        {
            ans += max(abs(left), abs(right));
        }
        tmp = left + right;
        if (!root->val)
        {
            if (tmp <= 0)
            {
                ans++;
            }
            tmp--;
        }
        else
        {
            if (tmp < 0)
            {
                ans -= min(abs(tmp), root->val - 1);
            }
            tmp += root->val - 1;
        }
        return tmp;
    }
    int distributeCoins(TreeNode *root)
    {
        recur(root);
        return ans;
        dfadsf
        }
};