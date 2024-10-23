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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        queue<int> level;
        level.push(0);
        int preLevel = 0;
        int valueStack = 0;

        if (root->left)
        {
            valueStack += root->left->val;
        }
        if (root->right)
        {
            valueStack += root->right->val;
        }
        int vS2 = valueStack * -1;
        queue<TreeNode *> sL;
        q.push(root);
        root->val = 0;

        // 부모가 자식값 모으는것도 하고. 자식값에서 자기자신과 형제 빼는것도 하고,
        while (!q.empty())
        {
            TreeNode *now = q.front();
            int lvl = level.front();
            q.pop();
            level.pop();

            if (lvl - 2 == preLevel)
            {
                // cout << valueStack << '\n';
                valueStack = vS2;
                vS2 = 0;
                preLevel++;
            }
            if (lvl - 1 == preLevel)
            {
                now->val += valueStack;
                // cout << valueStack << '\n';
            }
            int lv = 0;
            int rV = 0;
            if (now->left)
            {
                lv += now->left->val;
                vS2 += now->left->val;
                now->left->val *= -1;
                sL.push(now->left);
                q.push(now->left);
                level.push(lvl + 1);
            }
            if (now->right)
            {
                rV += now->right->val;
                vS2 += now->right->val;
                now->right->val *= -1;
                sL.push(now->right);
                q.push(now->right);
                level.push(lvl + 1);
            }
            if (now->left)
            {
                now->left->val -= rV;
            }
            if (now->right)
            {
                now->right->val -= lv;
            }
        }
        return root;
    }
};