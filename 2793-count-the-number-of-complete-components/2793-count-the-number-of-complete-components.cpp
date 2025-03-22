class Solution {
    vector<vector<int>> gEdges;
public:
    int dfs(int node, vector<vector<int>>& edges, vector<int>& visited, int& depth)
    {
        bool answer = true;
        for (int arg : edges[node])
        {
            if (visited[arg] == 1) continue;
            visited[arg] = 1;
            depth++;
            if (!dfs(arg, edges, visited, depth)) 
            {
                answer = false;
            }
        }
        // cout << node << ' ' << depth << ' ' << edges[node].size()  << '\n';
        if (depth != edges[node].size() + 1)
        {
            answer = false;
        }
        return answer;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        gEdges.resize(n + 1, {});

        for (vector<int>& edge : edges)
        {
            gEdges[edge[0]].push_back(edge[1]);
            gEdges[edge[1]].push_back(edge[0]);
        }

        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                int depth = 1;
                if (dfs(i, gEdges, visited, depth))
                {
                    answer++;
                }
            }
        }
        return answer;
    }

    
};