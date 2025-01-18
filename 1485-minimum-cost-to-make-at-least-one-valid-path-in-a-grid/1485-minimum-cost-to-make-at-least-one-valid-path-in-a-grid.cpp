#define checkCond(x, y, lx, ly) 0 <= (x) && (x) < (lx) && 0 <= (y) && (y) < (ly)
class Solution {
    int dx[4] {0, 0, 1, -1};
    int dy[4] {1, -1, 0, 0};
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // 1 <-> 2 , 3 <-> 4 이렇게 움직인다는게 보인다.
        // {cost, x, y} 
        int lx = grid.size();
        int ly = grid[0].size();
        vector<vector<int>> dp (lx, vector<int> (ly, INT_MAX));

        pq.push(vector<int> {0, 0, 0});

        while (pq.empty() == false)
        {
            int cost = pq.top()[0], x = pq.top()[1], y =  pq.top()[2];
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (i == grid[x][y] - 1)
                {
                    if (checkCond(nx, ny, lx, ly) && dp[nx][ny] > cost)
                    {
                        dp[nx][ny] = cost;
                        pq.push(vector<int> {cost, nx, ny});
                    }
                }
                else
                {
                    if (checkCond(nx, ny, lx, ly) && dp[nx][ny] > cost + 1)
                    {
                        dp[nx][ny] = cost + 1;
                        pq.push(vector<int> {cost + 1, nx, ny});
                    }
                }
            }
        }
        return dp[lx - 1][ly - 1] % INT_MAX;
    }
};