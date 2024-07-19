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
    int parents[1025][11] = {0};
    int heights[1025] = {0};
    vector<TreeNode *> indexToNode{};
    vector<int> leafNodesIndex{};
    int answer = 0;

public:
    int search(TreeNode *root, int height)
    {
        bool isLeaf = true;
        int myIndex = indexToNode.size();
        indexToNode.push_back(root);
        heights[myIndex] = height;

        if (root->left)
        {
            isLeaf = false;
            int leftChildIndex = search(root->left, height + 1);
            parents[leftChildIndex][0] = myIndex;
        }
        if (root->right)
        {
            isLeaf = false;
            int rightChildIndex = search(root->right, height + 1);
            parents[rightChildIndex][0] = myIndex;
        }

        if (isLeaf)
        {
            leafNodesIndex.push_back(myIndex);
        }
        return myIndex;
    }

    void fillParents()
    {
        int maxNode = indexToNode.size();
        int maxHeight = 1;
        int maxHeightP = 0;

        while (maxNode > maxHeight)
        {
            maxHeight *= 2;
            maxHeightP++;
        }

        for (int i = 1; i <= maxHeightP; i++)
        {
            for (int node = 0; node < maxNode; node++)
            {
                parents[node][i] = parents[parents[node][i - 1]][i - 1];
            }
        }
    }

    void getDIstanceBetween(int a, int b, int limit)
    {
        int distance = 0;
        if (heights[a] < heights[b])
        {
            swap(a, b);
        }

        if (heights[a] - heights[b] > limit)
        {
            return;
        }
        while (a != b)
        {
            if (distance > limit)
                return;
            if (heights[a] == heights[b])
            {
                if (parents[a][0] == parents[b][0])
                {
                    a = parents[a][0];
                    b = parents[b][0];
                    distance += 2;
                }
                int maxHeight = 1;
                int maxHeightP = 0;
                while (heights[a] > maxHeight)
                {
                    maxHeight *= 2;
                    maxHeightP++;
                }

                for (int i = maxHeightP; i >= 0; i--)
                {
                    if (parents[a][i] != parents[b][i])
                    {
                        distance += 2 * pow(2, i);
                        a = parents[a][i];
                        b = parents[b][i];
                        break;
                    }
                }
                continue;
            }
            else
            {
                for (int i = 10; i >= 0; i--)
                {
                    if (heights[parents[a][i]] >= heights[b])
                    {
                        a = parents[a][i];
                        distance += pow(2, i);
                    }
                }
            }
        }
        if (distance <= limit)
        {
            answer++;
        }
    }

    int countPairs(TreeNode *root, int distance)
    {
        search(root, 0);
        fillParents();
        for (int i = 0; i < leafNodesIndex.size(); i++)
        {
            for (int j = i + 1; j < leafNodesIndex.size(); j++)
            {
                getDIstanceBetween(leafNodesIndex[i], leafNodesIndex[j], distance);
            }
        }
        return answer;
    }
};