#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int tCount = 0;

    vector<vector<int>> visited;

    int dfs(int x, int y, vector<vector<int>> &grid)
    {
        int fThis = 0;
        int fParent = 4;
        tCount++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size() && grid[nx][ny])
            {
                fThis++;
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    fParent = min(fParent, dfs(nx, ny, grid));
                }
            }
        }
        return min(fThis, fParent);
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        visited = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
        bool oneIsland = true;
        int answer = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    if (oneIsland)
                    {
                        visited[i][j] = 1;
                        oneIsland = false;
                        answer = dfs(i, j, grid);
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }

        if (tCount <= 2)
        {
            return tCount;
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    visited = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
                    visited[i][j] = 1;
                    int tTime = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size() && grid[nx][ny])
                        {

                            if (!visited[nx][ny])
                            {
                                visited[nx][ny] = 1;
                                dfs(nx, ny, grid);
                                tTime++;
                            }
                        }
                    }
                    if (tTime > 1)
                    {
                        return 1;
                    }
                }
            }
        }

        return answer;
    }
};