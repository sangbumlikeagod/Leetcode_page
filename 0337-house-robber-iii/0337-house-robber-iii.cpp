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

    vector<vector<int>> dp;
    unordered_map<TreeNode*, int> possible;

    int dfs(TreeNode* node, bool canSteal)
    {
        int ans = 0;
        int idx = 0;
        if (possible.find(node) == possible.end())
        {
            possible[node] = possible.size();
        }
        idx = possible[node];
        if (dp[idx][canSteal]) return dp[idx][canSteal];


        
        if (node -> left && node -> right)
        {
            ans = max(ans, dfs(node -> left,true) + dfs(node -> right,true));
            if (canSteal)
            {
                ans = max(ans, node -> val + dfs(node -> left, false) + dfs(node -> right, false));
            }
        }
        else if (node -> left)
        {
            ans = max(ans, dfs(node -> left, true));
            if (canSteal)
            {
                ans = max(ans, node -> val + dfs(node -> left, false));
            }
        }
        else  if (node -> right)
        {
            ans = max(ans, dfs(node -> right, true));
            if (canSteal)
            {
                ans = max(ans, node -> val + dfs(node -> right, false));
            }
        }
        else
        {
            ans = canSteal ? node -> val : 0;
        }
        dp[idx][canSteal] = ans;
        // cout << node -> val << ' ' << idx << ' ' << canSteal << '\t' << ans << '\n';
        return dp[idx][canSteal];
    }
public:
    int rob(TreeNode* root) {

        dp.resize(10001, vector<int>(2));
        int idx = 0;
        return dfs(root, true);

    }
};