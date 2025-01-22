class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size(), c =isWater[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        queue<vector<int>> q;
        queue<vector<int>> q_next;
        vector<vector<int>> answer (r, vector<int>(c, -1));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (isWater[i][j]) 
                {
                    q.push({i, j, 0});
                    answer[i][j] = 0;
                }
            }
        }

        while (true)
        {
            while (q.empty() == 0)
            {
                int x = q.front()[0], y = q.front()[1], n = q.front()[2];
                q.pop();
                // cout << x << ' ' << y << ' ' << n << '\n';
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (0 <= nx && nx < r && 0 <= ny && ny < c && answer[nx][ny] == -1)
                    {
                        q_next.push(vector<int> {nx, ny, n + 1});
                        answer[nx][ny] = n + 1;
                    }
                }
            }
            // cout << '\t' << '\n';
            swap(q, q_next);
            if (q.empty()) break;
        }
        return answer;

    }
};