class Solution {
    private int[][] dp;
    private Integer MINIMUM = -5000000;
    private Integer MAXIMUM = 5000000;

    private Integer DP(int idx, int[] stoneValue) {
        int val = 0;
        int ans = MINIMUM;
        if (idx >= stoneValue.length) return 0;
        if (
            dp[idx][0] != MAXIMUM || 
            dp[idx][1] != MAXIMUM || 
            dp[idx][2] != MAXIMUM
        )
        {
            if (dp[idx][0] != MAXIMUM)
            {
                ans = Math.max(ans, dp[idx][0]);
            }
            if (dp[idx][1] != MAXIMUM)
            {
                ans = Math.max(ans, dp[idx][1]);
            }
            if (dp[idx][2] != MAXIMUM)
            {
                ans = Math.max(ans, dp[idx][2]);
            }
            // ans = Math.max(dp[idx][0], dp[idx][1]);
            // ans = Math.max(dp[idx][2], ans);
            return ans;
        }
        for (int i = 0; i < 3; i++)
        {
            if (idx + i >= stoneValue.length)
            {
                break;
            }
            val += stoneValue[idx + i];
            // 되는 애들 중에서 
            for (int j = 1; j <= 3; j++)
            {
                dp[idx][i] = Math.min(
                    dp[idx][i], 
                    DP(idx + i + j + 1, stoneValue) + val
                );
            }
            ans = Math.max(ans, dp[idx][i]);
        }
        return ans;
    }
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;
        dp = new int[n][3];
        Integer mm = Arrays.stream(stoneValue).sum();
        // System.out.println(mm);
        // Arrays.fill(dp[0], MAXIMUM);
        // Arrays.fill(dp[1], MAXIMUM);
        // Arrays.fill(dp[2], MAXIMUM);
        for (int i = 0; i < n; i++)
        {
            Arrays.fill(dp[i], MAXIMUM);
        }
        int nn = DP(0, stoneValue);
        // System.out.println(Arrays.deepToString(dp));
        if (mm == 2 * nn)
        {
            return "Tie";
        }
        else if (mm > 2 * nn)
        {
            return "Bob";
        }
        return "Alice";
    }
}