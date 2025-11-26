class Solution {
    private final int MODULO = ((int) 1e9) + 7; 
    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        long [][][] dp = new long[m + 1][n + 1][k];
        
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                for (int x = 0; x < k; x++)
                {
                    if (dp[i][j][x] == 0) continue;
                    if (i != m - 1)
                    {
                        dp[i + 1][j][(x + grid[i + 1][j]) % k] += dp[i][j][x];
                        dp[i + 1][j][(x + grid[i + 1][j]) % k] %= MODULO;
                    }
                    if (j != n - 1)
                    {
                        dp[i][j + 1][(x + grid[i][j + 1]) % k] += dp[i][j][x];
                        dp[i][j + 1][(x + grid[i][j + 1]) % k] %= MODULO;
                    }
                }
            }
        }
        return (int) dp[m - 1][n - 1][0];
    }
}