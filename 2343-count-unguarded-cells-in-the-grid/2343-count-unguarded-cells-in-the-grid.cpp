#define BOUNDARY(x, y, r, c)  0 <= (x) && (x) < (r) && 0 <= (y) && (y) < (c)
class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> table(m, vector<int> (n, 0));
        int answer = m * n;
        for (vector<int> wall : walls)
        {
            table[wall[0]][wall[1]] = 1;
            answer--;
        }

        for (vector<int> guard : guards)
        {
            int pyo = 2;
            for (int i = 0; i < 4; i++)
            {
                int nx = guard[0], ny = guard[1];
                while (BOUNDARY(nx, ny, m, n) && !(table[nx][ny] & (pyo + 1)))
                {
                    if (!table[nx][ny])
                    {
                        answer--;
                    } 
                    table[nx][ny] ^= pyo;
                    nx += dx[i];
                    ny += dy[i];
                }
                pyo *= 2;
            }
        }
        return answer;
    }
};