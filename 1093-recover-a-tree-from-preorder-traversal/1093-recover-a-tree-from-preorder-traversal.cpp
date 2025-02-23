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
    vector<int> traversalOrderInt;

private:
    void dfs(int& index, int depth, TreeNode* root, string& traversal)
    {
        // 내 현재 index는 반드시 마지막 숫자 마지막 인덱스. 
        // cout << index << '\n';
        // left를 탐색
        int left_copy = index + 1;
        while (left_copy != index + depth + 1)
        {
            if (traversal[left_copy] != '-')
            {
                break;
            }
            left_copy++;
        }
        if (left_copy == index + depth + 1)
        {
            // 내 depth보다 깊은놈이 옆에 있을리 없기 때문에 여기서 숫자인지는 확인할 필요 없음
            string a = "";
            while ('0' <= traversal[left_copy] && traversal[left_copy] <= '9')
            {
                a += traversal[left_copy];
                left_copy++;
            }
            root -> left = new TreeNode(stoi(a));
            index = left_copy - 1;
            dfs(index, depth + 1, root -> left, traversal);
        }

        int right_copy = index + 1;
        while (right_copy != index + depth + 1)
        {
            if (traversal[right_copy] != '-')
            {
                break;
            }
            right_copy++;
        }
        if (right_copy == index + depth + 1)
        {
            // 내 depth보다 깊은놈이 옆에 있을리 없기 때문에 여기서 숫자인지는 확인할 필요 없음
            string a = "";
            while ('0' <= traversal[right_copy] && traversal[right_copy] <= '9')
            {
                a += traversal[right_copy];
                right_copy++;
            }
            root -> right = new TreeNode(stoi(a));
            index = right_copy - 1;
            dfs(index, depth + 1, root -> right, traversal);
        }
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        string a;
        while ('0' <= traversal[index] && traversal[index] <= '9')
        {
            a += traversal[index];
            index++;
        }
        index--;
        TreeNode* root = new TreeNode(stoi(a));
        dfs(index, 1, root, traversal);
        return root;
    }
};