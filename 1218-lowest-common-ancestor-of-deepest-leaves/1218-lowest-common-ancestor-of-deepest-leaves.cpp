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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q1_copy;
        queue<TreeNode*> q2;

        vector<int> visited (1001, 0);

        vector<TreeNode*> parents(1001, nullptr);
        parents[root -> val] = root;
        q1.push(root);
        while (true)
        {
            while (q1.empty() == false)
            {
                TreeNode* next = q1.front();
                q1_copy.push(next);
                q1.pop();
                if (next -> left)
                {
                    parents[next -> left -> val] = next;
                    q2.push(next -> left);
                }
                if (next -> right)
                {
                    parents[next -> right -> val] = next;
                    q2.push(next -> right);
                }
            }
            if (q2.empty())
            {
                swap(q1, q1_copy);
                break;
            }
            q1_copy = queue<TreeNode*>();
            swap(q1, q2);
        }



        while (true)
        { 
            if (q1.size() == 1) break;
            while (q1.empty() == false)
            {
                TreeNode* next = q1.front();
                q1.pop();
                if (visited[parents[next -> val] -> val] == 0)
                {
                    visited[parents[next -> val] -> val] = 1;
                    q2.push(parents[next -> val]);
                }
            }
            swap(q1, q2);
        }
        return q1.front();
        

        
        

    }
};