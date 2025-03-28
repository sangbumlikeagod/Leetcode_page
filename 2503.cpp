class Solution {
    int dx[4] {0, 0, 1, -1};
    int dy[4] {1, -1, 0, 0};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));        
        vector<pair<int, int>> queryIndex;
        for (int i = 0; i < queries.size(); i++)
        {
            queryIndex.push_back({queries[i], i});
        }

        vector<int> answer(queries.size());
        sort(queryIndex.begin(), queryIndex.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push(vector<int>{grid[0][0], 0, 0});
        visited[0][0] = 1;
        int count = 0;


        for (pair<int, int>& arg : queryIndex)
        {
            // cout << '\t' << arg.first << '\n';
            while(q.empty() == false && arg.first > q.top()[0])
            {
                vector<int> next = q.top();
                q.pop();

                // cout << next[0] << ' ' << next[1] << ' ' << next[2] << '\n';
                // if (arg.first > next[0])
                {
                    count++;
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = next[1] + dx[i];
                        int ny = next[2] + dy[i];
                        if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size() && visited[nx][ny] == 0)
                        {
                            visited[nx][ny] = 1;
                            q.push(vector<int> {grid[nx][ny], nx, ny});
                        }
                    }
                }
                if (q.empty())
                {
                    break;
                }
            }
            answer[arg.second] = count;
        }

        return answer;
    }
};