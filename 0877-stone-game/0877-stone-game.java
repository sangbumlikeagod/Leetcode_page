class Solution {
    private int[][] dp;
    private int DP(int l, int r, int[] piles) {
        
        if (l >= r) return 0;
        if (dp[l][r] != 0)
        {
            return dp[l][r];    
        }
        
        
        
        dp[l][r] = Math.max(
            dp[l][r],
            DP(l + 2, r, piles) + piles[l]
        );
        dp[l][r] = Math.max(
            dp[l][r],
            DP(l + 1, r - 1, piles) + Math.max(piles[l], piles[r])
        );
            
        dp[l][r] = Math.max(
            dp[l][r],
            DP(l, r - 2, piles) + piles[r]
        );
        
        return dp[l][r];

    }
    public boolean stoneGame(int[] piles)
        {
        
        int aScore = 0;
        int bScore = 0;
        
        int l = 0;
        int r = piles.length;
        
        dp = new int[r][r];
        int total = 0;
        
        for (int num : piles)
        {
            total += num;
        }
        
        int result = DP(l, r - 1, piles);

        
        return result > (total / 2);
    }
}