class Solution {
private:
  int bfs_(int node, vector<vector<int>>& adjList, int n)
  {
    vector<int> visited (n + 1, 0);
    queue<int> q;
    queue<int> q_;
    q.push(node);
    int depth = 1;
    int ret = 0;
    visited[node] = 1;
    while (true)
    {
        while (q.empty() == false)
        {
            int nd = q.front();
            q.pop();
            for (int next : adjList[nd])
            {
                if (visited[next]) continue;
                {
                    visited[next] = 1;
                    q_.push(next);
                }
            }
        }
        swap(q, q_);
        if (q.empty()) {break;}
        depth++;
    }
    return depth;
  }

  int dfs_(int node, vector<vector<int>>& adjList, int n, vector<int>& visited, vector<int>& lengths)
  {
    int ret = lengths[node];
    for (int next : adjList[node])
    {
        if (visited[next]) continue;
        visited[next] = 1;
        ret = max(ret, dfs_(next, adjList,  n, visited, lengths));
    }
    return ret;
  }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> visited(n + 1, 0);
        vector<int> visited2(n + 1, 0);
        vector<int> lengths(n + 1, 0);
        vector<int> heights(n + 1, 0);
        vector<vector<int>> adjList (n + 1, vector<int> {});
        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                heights[i] = 1;

                queue<int> q; 
                q.push(i);
                // bfs 여기서 시작 
                while (q.empty() == false)
                {
                    int nxt = q.front();
                    int height = heights[nxt];
                    q.pop();
                    for (int next : adjList[nxt])
                    {
                        if (visited[next])
                        {
                            if (height - 1 == heights[next]) continue;

                            if (height + 1 != heights[next])
                            {
                                return -1;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        heights[next] = height + 1;
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        int answer = 0;
        for (int i = 1; i <= n; i++)
        {
            lengths[i] = bfs_(i, adjList, n);
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited2[i]) continue;
            visited2[i] = 1;
            answer += dfs_(i, adjList, n, visited2, lengths);
        }
        return answer;
    }
};