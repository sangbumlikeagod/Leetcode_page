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
public:
    bool compareFlips(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;

        int status = needToFlip(root1, root2);
        if (status == 1)
        {
            return compareFlips(root1->left, root2->right) &&
                   compareFlips(root1->right, root2->left);
        }
        else if (status == 0)
        {
            return compareFlips(root1->left, root2->left) &&
                   compareFlips(root1->right, root2->right);
        }
        else
        {
            return false;
        }
    }

    int needToFlip(TreeNode *root1, TreeNode *root2)
    {
        if (root1->left && root2->left && root1->right && root2->right)
        {
            if (root1->left->val == root2->right->val &&
                root2->left->val == root1->right->val)
            {
                return 1;
            }
            else if (root1->left->val == root2->left->val &&
                     root2->right->val == root1->right->val)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        else if (root1->left && root2->left && !root1->right && !root2->right)
        {
            return root1->left->val == root2->left->val ? 0 : -1;
        }
        else if (!root1->left && !root2->left && root1->right && root2->right)
        {
            return root1->right->val == root2->right->val ? 0 : -1;
        }
        else if (root1->left && !root2->left && !root1->right && root2->right)
        {
            return root1->left->val == root2->right->val ? 1 : -1;
        }
        else if (!root1->left && root2->left && root1->right && !root2->right)
        {
            return root1->right->val == root2->left->val ? 1 : -1;
        }
        else if (!root1->left && !root2->left && !root1->right && !root2->right)
        {
            return 1;
        }
        return -1;
    }

    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        else if (!root1 || !root2)
        {
            return false;
        }
        if (root1->val != root2->val)
            return false;
        return compareFlips(root1, root2);
    }
};