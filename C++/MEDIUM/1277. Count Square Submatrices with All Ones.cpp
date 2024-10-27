class Solution
{
    queue<vector<int>> q;

public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int answer = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j])
                {
                    q.push({i, j, 2});
                    answer++;
                }
            }
        }

        while (!q.empty())
        {
            int x = q.front()[0], y = q.front()[1], w = q.front()[2];
            // cout << x << ' ' << y << '\n';
            q.pop();
            int isPossible = true;
            if (x + w > m || y + w > n)
                continue;
            for (int i = x; i < x + w; i++)
            {
                if (!matrix[i][y + w - 1])
                {
                    isPossible = false;
                    break;
                }
            }
            for (int i = y; i < y + w; i++)
            {
                if (!matrix[x + w - 1][i])
                {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible)
            {
                answer++;
                q.push({x, y, w + 1});
            }
        }
        return answer;
    }
};