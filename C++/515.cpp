#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    //  TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

vector<int> recur(queue<TreeNode*>* q){
    queue<TreeNode*> nq;
    int maxx;
    maxx = -pow(2, 31);
    while ((*q).empty() == false){
        if (((*q).front() -> left) != nullptr){
            nq.push((*q).front() -> left);
        }
        if (((*q).front() -> right) != nullptr){
            nq.push((*q).front() -> right);
        }
        if ((*q).front() -> val > maxx){
            maxx = (*q).front() -> val;
        }
        (*q).pop();
    };
    vector<int> ans = {maxx};
    if (nq.empty()){
        return ans;
     }
    vector<int> past = recur(&nq);
    for (int i: past){
        ans.push_back(i);
    }
    return ans;
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        return recur(&q);
    }
};

int WinMain(){
    queue<TreeNode*> q;
}


prhdfdsa