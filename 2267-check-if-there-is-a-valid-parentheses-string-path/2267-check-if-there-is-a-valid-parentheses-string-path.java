class Solution {
    public boolean hasValidPath(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][][] DP = new int[m][n][201];
        // 시작이 -1일 수는 없음 
        if (grid[0][0] == ')') return false;

        DP[0][0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k <= 200; k++)
                {   
                    // 1개라도 남아있으면 
                    if (DP[i][j][k] != 1)
                    {
                        continue;
                    }
                    if (grid[i][j] == '(')
                    {
                        if (i != m - 1)
                        {
                            DP[i + 1][j][k + 1] = 1;
                        }
                        if (j != n - 1)
                        {
                            DP[i][j + 1][k + 1] = 1;
                        }
                    }
                    if (grid[i][j] == ')' && k != 0)
                    {
                        if (i != m - 1)
                        {
                            DP[i + 1][j][k - 1] = 1;
                        }
                        if (j != n - 1)
                        {
                            DP[i][j + 1][k - 1] = 1;
                        }
                    }
                }
            }
        }

        return (grid[m - 1][n - 1] == ')') &&  (DP[m - 1][n - 1][1] == 1);
    }
}