class Solution {
    private static int MODULO = (int) 1e9 + 7; 
    public int numberOfWays(int n, int x) {
        int[][] dp = new int[n + 2][n + 1];
        dp[1][0] = 1;
        int m = 1;
        while ((int) Math.pow(m + 1, x) <= n)
        {
            m++;
        }
        // System.out.println(m);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (dp[i][j] == 0) 
                {
                    continue;
                }

                {
                    if ((int) Math.pow(i, x) + j <= n)
                    {
                        // System.out.println(i + ", " + ((int) Math.pow(i, x) + j));
                        dp[i + 1][(int) Math.pow(i, x) + j] += dp[i][j];
                        dp[i + 1][(int) Math.pow(i, x) + j] %= MODULO;
                    }

                    {
                        // System.out.println(" " + i + ", " + j);
                        dp[i + 1][j] += dp[i][j];
                        dp[i + 1][j] %= MODULO;
                    }
                    
                }
            }
        }
        return dp[m + 1][n];
    }
}

