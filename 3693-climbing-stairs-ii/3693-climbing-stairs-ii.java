class Solution {
    public int climbStairs(int n, int[] costs) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, (int) 1e9 + 7);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (i + j > n) break;
                dp[i + j] = Math.min(dp[i + j], dp[i] + (j) * (j) + costs[i + j - 1]);
            }
        }
        return dp[n];
    }
}