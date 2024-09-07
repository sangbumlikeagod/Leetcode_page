/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

private:
    bool DFS(TreeNode *node, ListNode *index)
    {
        bool result = false;
        bool key = index->val == node->val;
        if (key)
        {
            result = index->next ? DFS_HeadFound(node, index) : true;
        }
        if (node->left)
        {
            result |= DFS(node->left, index);
        }
        if (node->right)
        {
            result |= DFS(node->right, index);
        }
        return result;
    }
    bool DFS_HeadFound(TreeNode *node, ListNode *index)
    {
        bool result = false;

        if (!index->next)
        {
            return true;
        }

        if (node->left && node->left->val == index->next->val)
        {
            if (index->next)
            {
                result |= DFS(node->left, index->next);
            }
        }

        if (!result && node->right)
        {
            if (index->next && node->right->val == index->next->val)
            {
                result |= DFS(node->right, index->next);
            }
        }
        return result;
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        return DFS(root, head);
    }
};