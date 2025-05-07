class Solution {
    int MAXVAL = 1e9 + 1000;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> dp(m, vector<int> (n, MAXVAL));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push(vector<int> {0, 0, 0});
        dp[0][0] = 0;
        while (pq.empty() == false)
        {
            // cout << pq.size() << '\n';
            auto& next = pq.top();
            int v = next[0];
            int x = next[1];
            int y = next[2];
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < m && 0 <= ny && ny < n)
                {
                    int nv = max(v + 1, moveTime[nx][ny] + 1);
                    if (nv && v + 1 < dp[nx][ny])
                    {
                        dp[nx][ny] = nv;
                        pq.push(vector<int> {nv, nx, ny});
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};