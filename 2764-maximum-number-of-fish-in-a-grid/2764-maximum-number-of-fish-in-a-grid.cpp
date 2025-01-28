#define qualify(x, y, lx, ly) 0 <= (x) && (x) < (lx) && 0 <= (y) && (y) < (ly)
class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        int answer = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (visited[i][j] == 0 && grid[i][j])
                {
                    visited[i][j] = 1;
                    answer = max(answer, dfs(i, j, visited, grid));
                }
            }
        }
        return answer;
    }

    int dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        int tmp = 0;
        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (qualify(nx, ny, grid.size(), grid[0].size()) && visited[nx][ny] == 0 && grid[nx][ny])
            {
                visited[nx][ny] = 1;
                tmp += dfs(nx, ny, visited, grid);
            }
        }
        return tmp + grid[i][j];
    }
};