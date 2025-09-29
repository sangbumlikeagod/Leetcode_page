class Solution {
    private int[][] dp = new int[51][51];

    private int DP(int l, int r, int[] values)
    {
        // System.out.println(l + " " + r);
        if (dp[l][r] != Integer.MAX_VALUE)
        {
            return dp[l][r];
        }
        if (r - l == 2)
        {
            dp[l][r] =  values[l] * values[r] * values[l + 1];
        }
        else
        {
            for (int i = l + 2; i < r - 1; i++)
            {
                int lx = DP(l, i, values);
                int rx = DP(i, r, values);
                int remain = values[l] * values[r] * values[i];
                dp[l][r] = Math.min(dp[l][r], lx + rx + remain);
            }
            dp[l][r] = Math.min(dp[l][r], DP(l + 1, r, values) + values[l] * values[r] * values[l + 1]);
            dp[l][r] = Math.min(dp[l][r], DP(l, r - 1, values) + values[l] * values[r] * values[r - 1]);
        }
        return dp[l][r];
    }
    public int minScoreTriangulation(int[] values) {    
        for (int i =0; i <= 50; i++)
        {
            for (int j = 0; j <= 50; j++)
            {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }


        return DP(0, values.length - 1, values);
    }
}