class Solution {
    vector<vector<int>> adjLists;
    vector<vector<int>> adjLists2;

    pair<int, int> dfs(bool isEven, int num, vector<int>& visited, vector<vector<int>>& adjList)
    {
        // 홀수 vs 짝수
        pair<int, int> ret = {!isEven, isEven};
        for (int arg : adjList[num])
        {
            if (visited[arg] == 0)
            {
                visited[arg] = !isEven + 1;
                pair<int,int> ans = dfs(!isEven, arg, visited, adjList);
                ret.first += ans.first;
                ret.second += ans.second;
            }
        }
        return ret;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m = edges1.size(), n = edges2.size();
        adjLists.resize(m + 1);
        adjLists2.resize(n + 1);

        for (vector<int>& edge : edges1)
            {
                adjLists[edge[0]].push_back(edge[1]);
                adjLists[edge[1]].push_back(edge[0]);
            }
        for (vector<int>& edge : edges2)
            {
                adjLists2[edge[0]].push_back(edge[1]);
                adjLists2[edge[1]].push_back(edge[0]);
            }
        vector<int> visited1 (m + 1);
        visited1[0]  = 2;
        pair<int, int> pair1 = dfs(true, 0, visited1, adjLists);
        
        vector<int> visited2 (n + 1);
        visited2[0]  = 2;
        pair<int, int> pair2 = dfs(true, 0, visited2, adjLists2);

        for (int i = 0; i <= m; i++)
            {
                if (visited1[i] == 2)
                {
                    visited1[i] = pair1.second + max(pair2.first, pair2.second);
                }
                else
                {
                    visited1[i] = pair1.first + max(pair2.first, pair2.second);
                }
            }
        return visited1;
    }
};