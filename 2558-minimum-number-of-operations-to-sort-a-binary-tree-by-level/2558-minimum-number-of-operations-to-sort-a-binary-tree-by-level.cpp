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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> q_copy;
        q.push(root);

        vector<pair<int, int>> pos;
        vector<int> visited;
        int answer = 0;
        while (true)
        {
            pos.clear();
            int idx = 0;
            int tmp = 0;
            while (q.empty() == false)
            {
                if (q.front() -> left)
                {
                    q_copy.push(q.front() -> left);
                    pos.push_back({q.front() -> left -> val, idx});
                    idx++;
                }
                if (q.front() -> right)
                {
                    q_copy.push(q.front() -> right);
                    pos.push_back({q.front() -> right -> val, idx});
                    idx++;
                }
                q.pop();
            }
            sort(pos.begin(), pos.end());
            visited = vector<int> (pos.size(), 0);

            for (int i = 0; i < pos.size(); i++)
            {
                if (!visited[i])
                {
                    visited[i] = 1;
                    answer += dfs(i, pos, visited) - 1;
                }
            }
            swap(q, q_copy);
            if (q.empty())
            {
                break;
            }
        }

        return answer;
    }

private:
    int dfs(int x, vector<pair<int, int>>& pos, vector<int>& visited)
    {
        int next = pos[x].second;
        if (!visited[next])
        {
            visited[next] = 1;
            return dfs(next, pos, visited) + 1;
        }
        return 1;
    }
};