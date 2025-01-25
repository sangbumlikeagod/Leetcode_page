#define isborder(r, c, n) 0 <= (r) && (r) < (n) && 0 <= (c) && (c) < (n)  
class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    map<pair<int, int>, int> cycleKV;
    int n;

public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> cycleFreq {};
        long long SS = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != -1)
                {
                    cnt++;
                    if (cycleKV.find({i, j}) == cycleKV.end())
                    {
                        int nxt = cycleFreq.size();
                        cycleFreq.push_back(0);
                        cycleKV[{i, j}] = nxt;
                        dfs(SS, i, j, nxt, grid, cycleFreq);
                    }
                }
            }
        }
        SS *= (cnt - 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != -1)
                {
                    long long tmp = grid[i][j];
                    SS -= (cycleFreq[cycleKV[{i, j}]] - 1) * tmp;
                }
            }
        }
        return SS;
    }
private:
    void dfs(long long& sums, int r, int c, int cycleNum, vector<vector<int>>& grid,vector<int>& cycleFreq)
    {
        sums += grid[r][c];
        cycleFreq[cycleNum]++;
        for (int i = 0; i < 4; i++)
        {
            int nx = r + dx[i];
            int ny = c + dy[i];
            if (isborder(nx, ny, n) && grid[nx][ny] != -1 && cycleKV.find({nx, ny}) == cycleKV.end())
            {
                cycleKV[{nx, ny}] = cycleNum;
                dfs(sums, nx, ny, cycleNum, grid, cycleFreq);
            }
        }
    }
};