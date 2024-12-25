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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> q_copy;
        vector<int> answer;
        if (!root)
        {
            return answer;
        }
        q.push(root);

        while(true)
        {
            int biggest = INT_MAX * -1 - 1;
            while(q.empty() == false)
            {
                biggest = max(biggest, q.front()->val);
                if (q.front()->left)
                {
                    q_copy.push(q.front()->left);
                }
                if (q.front()->right)
                {
                    q_copy.push(q.front()->right);
                }
                q.pop();
            }
            answer.push_back(biggest);
            swap(q, q_copy);
            if (q.empty())
            {
                break;
            }
        }
        return answer;
    }
};