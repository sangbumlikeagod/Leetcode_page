class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        queue<int> q;
        queue<int> q_parent;
        int nodeSize = values.size();
        vector<long long> nodeValues (nodeSize, 0);

        for (int i = 0; i < nodeSize; i++)
        {
            nodeValues[i] = values[i];
        }
        vector<int> nodeEdgeCount (nodeSize, 0);
        vector<int> nodeVisited (nodeSize, 0);
        vector<unordered_set<int>> nodeEdgeList (nodeSize, unordered_set<int> {});
        if (edges.empty())
        {
            return nodeSize;
        }
        for (vector<int> edge : edges)
        {
            nodeEdgeList[edge[0]].insert(edge[1]);
            nodeEdgeList[edge[1]].insert(edge[0]);
            nodeEdgeCount[edge[0]]++;
            nodeEdgeCount[edge[1]]++;
        }

        for (int i = 0; i < nodeSize; i++)
        {
            if (nodeEdgeCount[i] == 1)
            {
                q.push(i);
            }
        }
        int answer = 0;
        while (true)
        {
            while (q.empty() == false)
            {
                int child = q.front();
                q.pop();

                nodeVisited[child] = 1;

                if (nodeEdgeList[child].empty())
                {
                    answer++;
                    break;
                }
                int parent = *(nodeEdgeList[child].begin());
                nodeEdgeList[parent].erase(child);
                nodeEdgeCount[parent]--;
                nodeEdgeCount[child]--;
                // 내가 이미 부모가 됐단 뜻
                // if (nodeVisited[parent])
                // {
                //     if (values[child] % k == 0)
                //     {
                //         answer++;
                //     }
                //     continue;
                // }

                if (nodeValues[child] % k == 0)
                {
                    answer++;
                }
                else
                {
                    nodeValues[parent] += nodeValues[child];
                }
                if (nodeEdgeCount[parent] == 1)
                {
                    q_parent.push(parent);
                }
            }
            swap(q, q_parent);

            if (q.empty())
                break;
        }
        return answer;
    }
};