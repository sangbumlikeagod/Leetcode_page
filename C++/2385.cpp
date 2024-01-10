/**
  Definition for a binary tree node.
  */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> undirectedGraph;
public:
    int amountOfTime(TreeNode* root, int start) {
        undirected_graph(root);
        unordered_set<int> visited;
        queue<int> q;

        q.push(start);
        int ans = -1;
        while (!q.empty()){
            ans++;
            for (int i = 0; i < q.size(); i++)
            {
                int next = q.front();
                q.pop();
                visited.insert(next);
                for (int arg : undirectedGraph[next])
                {
                    if (!visited.count(arg)){
                        q.push(arg);
                    }
                }
            }
            
        }
        return ans;
    }
    void undirected_graph(TreeNode* root){
        if (root->left != nullptr){
            undirectedGraph[root->left->val].push_back(root->val);
            undirectedGraph[root->val].push_back(root->left->val);
            undirected_graph(root->left);
        }
        if (root->right != nullptr)
        {
            undirectedGraph[root->right->val].push_back(root->val);
            undirectedGraph[root->val].push_back(root->right->val);
            undirected_graph(root->right);
        }
        
    }
};