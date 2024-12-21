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
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*> q;
        deque<TreeNode*> q_copy;

        q.push_back(root);
        int level = 1;  

        while (true)
        {
            vector<int> numbers;
            while(q.empty() == false)
            {
                if (q.front()->left)
                {
                    q_copy.push_back(q.front()->left);
                    if (level % 2)
                    {
                        numbers.push_back(q.front()->left->val);
                    }
                }
                if (q.front()->right)
                {
                    q_copy.push_back(q.front()->right);
                    if (level % 2)
                    {
                        numbers.push_back(q.front()->right->val);
                    }
                }
                q.pop_front();
            }

            if (level % 2)
            {
                auto qS = q_copy.begin();
                while (qS != q_copy.end())
                {
                    (*qS)->val = numbers.back();
                    numbers.pop_back();
                    qS++;
                }
            }
            level++;
            swap(q, q_copy);
            if (q.empty())
            {
                break;
            }
        }
        return root;

    }
};