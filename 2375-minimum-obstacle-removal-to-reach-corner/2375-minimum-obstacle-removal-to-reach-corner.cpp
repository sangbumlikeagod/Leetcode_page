class Solution {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    int dx[4] {0, 0, 1, -1};
    int dy[4] {1, -1, 0, 0};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp (grid.size(), vector<int> (grid[0].size(), 100001));
        q.push(vector<int> {0, 0, 0});
        while (!q.empty())
        {
            vector<int> ths = q.top();
            q.pop();
            int x = ths[1], y = ths[2];
            // cout << x << ' ' << y << ' ' << ths[0] << '\n';
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
            {
                return ths[0];
            }
            for (int i = 0; i < 4; i++)
            {
                int nx =  x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
                    continue;
                int ps = ths[0];
                if (grid[nx][ny])
                {
                    ps++;
                }
                if (ths[0] < dp[nx][ny])
                {
                    // cout << '\t' << nx << ' ' << ny << '\n';
                    dp[nx][ny] = ths[0];
                    q.push(vector<int> {ps, nx, ny});
                }
            }
        }
        return 100000;
    }   
};