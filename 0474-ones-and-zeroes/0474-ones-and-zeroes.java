class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int s = strs.length;
        int[] zeros = new int[s];
        int[] ones = new int[s];

        int answer = 1;
        for (int i = 0; i < s; i++) 
         {
            String str = strs[i];
             int z = 0, o = 0;
            for (char c : str.toCharArray())
            {
                if (c == '1')
                {
                    o++;
                }
                else
                {
                    z++;
                }
            }
             zeros[i] = z;
             ones[i] = o;
         }
        

        int[][][] dp = new int[s + 1][m + 1][n + 1];
        
        for (int i = 0; i < s; i++)
            {
                dp[i][0][0] = 1;
                int x = zeros[i];
                int y = ones[i];
                for (int j = 0; j <= m; j++)
                    {
                        for (int k = 0; k <= n; k++)
                        {
                            if (dp[i][j][k] > 0)
                            {
                                if (j + x <= m && k + y <= n)
                                {                    
                                    dp[i + 1][j + x][k + y] = Math.max(dp[i + 1][j + x][k + y], dp[i][j][k] + 1);
                                    answer = Math.max(answer, dp[i + 1][j + x][k + y]);
                                }
                                dp[i + 1][j][k] = Math.max(dp[i + 1][j][k], dp[i][j][k]);
                            }
                        }
                    }
            }

        
        return answer - 1;
    }
}