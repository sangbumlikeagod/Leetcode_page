class Solution {
    // 오른쪽 대각선부터
    int[] dx = {-1, 1, 1, -1};
    int[] dy = {1, 1, -1, -1};
    int m, n;

    private boolean isSafe(int i, int j)
    {
        return 0 <= i && i <m && 0 <= j && j < n;
    }
    private int _getLengthDataPerDir(int idx, int[][][] dp, int[][] grid, int i, int j)
    {
        if (dp[idx][i][j] != 0)
        {
            return dp[idx][i][j];
        }
        if (isSafe(i + dx[idx], j + dy[idx]) && (grid[i][j] + grid[i + dx[idx]][j + dy[idx]]) == 2)
        {
            dp[idx][i][j] = 1 + _getLengthDataPerDir(idx, dp, grid, i + dx[idx], j + dy[idx]);
        }
        else
        {
            dp[idx][i][j] = 1;
        }
        return dp[idx][i][j];
    }
    public int getTurnValue(int idx,int i, int j, int[][][] dp, int[][] grid)
    {
        int mul = 1;
        int ret = 0;
        if (!isSafe(i + dx[idx] * mul, j + dy[idx] * mul) || grid[i + dx[idx] * mul][j + dy[idx] * mul] != 2)
        {
            return 0;
        }
        // int initLength = dp[idx][i + dx[idx] * mul][j + dy[idx] * mul];
        while (isSafe(i + dx[idx] * mul, j + dy[idx] * mul) &&
         dp[idx][i + dx[idx] * mul][j + dy[idx] * mul] >= 1)
         {
            int nIdx = (idx + 1) % 4;
            ret = Math.max(ret, dp[nIdx][i + dx[idx] * mul][j + dy[idx] * mul] + mul - 1);
            if (dp[idx][i + dx[idx] * mul][j + dy[idx] * mul] == 1) break;
            mul++;
         }
         return ret;
    }
    public void getLengthDataPerDir(int idx, int[][][] dp, int[][] grid) {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 1)
                {
                    _getLengthDataPerDir(idx, dp, grid, i, j);
                }
            }
        }
    }

    public int lenOfVDiagonal(int[][] grid) {
        m = grid.length; n = grid[0].length;
        int[][][] dp = new int[4][m][n];
        for (int k = 0; k < 4; k++)
        {
            getLengthDataPerDir(k, dp, grid);
            // for (int i = 0; i < m; i++)
            // {
            //     for (int j = 0 ; j < n; j++)
            //     {
            //         System.out.print(dp[k][i][j]);
            //     }
            //     System.out.println();
            // }
            // System.out.println();
        }
        int answer = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0 ; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        dp[k][i][j] = Math.max(dp[k][i][j], getTurnValue(k, i, j, dp, grid) + 1);
                        answer = Math.max(answer, dp[k][i][j]);

                    }
                }
            }
        }

        // for (int k = 0; k < 4; k++)
        // {
        //     for (int i2 = 0; i2 < m; i2++)
        //     {
        //         for (int j2 = 0 ; j2 < n; j2++)
        //         {
        //             System.out.print(dp[k][i2][j2]);
        //         }
        //         System.out.println();
        //     }
        //     System.out.println();
        // }
        return answer;    
    }
}   