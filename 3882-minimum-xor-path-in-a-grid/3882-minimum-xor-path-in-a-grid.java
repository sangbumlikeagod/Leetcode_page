class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        int[][][] dps = new int[m][n][1024];


        dps[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 1024; k++)
                {
                    if (dps[i][j][k] == 0) continue;

                    if (j + 1 < n)
                    {
                        dps[i][j + 1][k ^ grid[i][j + 1]] = 1;
                    }
                    if (i + 1 < m)
                    {
                        dps[i + 1][j][k ^ grid[i + 1][j]] = 1;
                    }
                }
            }
        }
        for (int k = 0; k < 1024; k++)
        {
            if (dps[m - 1][n - 1][k] == 1)
            {
                return k;
            }
        }
        return 0;
    }
}
