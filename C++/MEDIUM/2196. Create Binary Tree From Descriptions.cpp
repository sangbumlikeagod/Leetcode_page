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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        vector<TreeNode *> palette(100001, nullptr);
        vector<int> beingChild(100001, 0);
        for (vector<int> description : descriptions)
        {
            if (!palette[description[0]])
            {
                palette[description[0]] = new TreeNode(description[0]);
            }
            if (!palette[description[1]])
            {
                palette[description[1]] = new TreeNode(description[1]);
            }
            if (description[2])
            {
                palette[description[0]]->left = palette[description[1]];
            }
            else
            {
                palette[description[0]]->right = palette[description[1]];
            }
            beingChild[description[1]]++;
        }
        for (int i = 0; i <= 100000; i++)
        {
            if (palette[i] && !beingChild[i])
            {
                return palette[i];
            }
        }
        return nullptr;
    }
};