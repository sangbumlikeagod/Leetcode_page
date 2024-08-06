class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        int isSecond = false;
        vector<vector<int>> adjList(n + 1, vector<int>{});
        vector<int> visited(n + 1, 0);
        vector<int> visitedValue(n + 1, 0);

        // 우선순위 큐로 가장 빠른 열 찾음
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for (vector<int> edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        visited[1] = 1;
        q.push({0, 1});

        while (!q.empty())
        {
            pair<int, int> next = q.top();
            // cout << next.first << ' ' << next.second << '\n';
            q.pop();
            if (next.second == n)
            {
                if (isSecond)
                {
                    return next.first;
                }
                isSecond = true;
            }

            int nNextTime = (next.first) / change;
            if (nNextTime % 2)
            {
                next.first = (nNextTime + 1) * change;
            }

            for (int nNext : adjList[next.second])
            {
                if (visited[nNext] == 2 || visitedValue[nNext] >= (next.first + time))
                    continue;
                visited[nNext]++;
                visitedValue[nNext] = (next.first + time);
                q.push({next.first + time, nNext});
            }
        }
        return -1;
    }
};