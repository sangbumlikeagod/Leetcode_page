class Solution
{
    int status[1000][1000]{0};

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        queue<int> q;
        vector<int> visited(n, 0);
        vector<vector<int>> answer(n, vector<int>{});
        vector<vector<int>> pointTo(n, vector<int>{});
        vector<vector<int>> pointedFrom(n, vector<int>{});

        for (vector<int> edge : edges)
        {
            pointedFrom[edge[1]].push_back(edge[0]);
            pointTo[edge[0]].push_back(edge[1]);
        }

        for (int index = 0; index < n; index++)
        {
            if (!pointedFrom[index].size())
            {
                visited[index] = 2;
                q.push(index);
            }
        }

        while (!q.empty())
        {
            int thTime = q.front();
            q.pop();
            bool yet = false;
            for (int before : pointedFrom[thTime])
            {
                if (visited[before] != 2)
                {
                    q.push(thTime);
                    yet = true;
                    break;
                }
            }
            if (yet)
            {
                continue;
            }
            visited[thTime] = 2;

            for (int next : pointTo[thTime])
            {
                status[next][thTime] = 1;
                if (!visited[next])
                {
                    visited[next] = 1;
                    q.push(next);
                }

                for (int poss = 0; poss < n; poss++)
                {
                    if (status[thTime][poss])
                    {
                        status[next][poss] = 1;
                    }
                }
            }
        }

        for (int index = 0; index < n; index++)
        {
            for (int poss = 0; poss < n; poss++)
            {
                if (status[index][poss])
                {
                    answer[index].push_back(poss);
                }
            }
        }
        return answer;
    }
};