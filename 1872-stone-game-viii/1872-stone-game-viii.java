class Solution {
    private int[][] dp;
    private int[] prefixStones;
    private Integer DP(
        int idx,
        int n,
        int isAlice, 
        int length
    )
    {
       
        // System.out.println(idx +  " " + isAlice + " " + length);
        if (idx >= n){
            return 0;
        }
        int totalSum = isAlice == 1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        if (dp[idx][isAlice] != totalSum)
        {
            // System.out.println(idx +  " " + isAlice);
            return dp[idx][isAlice];
        }
        // 그전까지는 이전값이 무조건 있기 떄문에 
        int mysSum = prefixStones[idx + 1] - prefixStones[0];
        int limit = idx == 0 ? 1 : 0;

        if (isAlice == 1)
        {
            // 남한테 넘기기 
            if (length > limit)
            {
                totalSum = Math.max(totalSum, DP(idx + 1, n, 0, 1)) + mysSum;
            }

            // 나한테 다시 턴 넘기기 맨 마지막이면 안됨 근데 
            if (idx != n - 1)
            {
                totalSum = Math.max(totalSum, DP(idx + 1, n, 1, length + 1));
            }
        }
        else
        {
            // 남한테 넘기기 
            if (length > limit)
            {
                totalSum = Math.min(totalSum, DP(idx + 1, n, 1, 1)) - mysSum;
            }

            // 나한테 다시 턴 넘기기 맨 마지막이면 안됨 근데 
            if (idx != n - 1)
            {
                totalSum = Math.min(totalSum, DP(idx + 1, n, 0, length + 1));
            }
        }


        dp[idx][isAlice] = totalSum;
        return dp[idx][isAlice];
    }

    public int stoneGameVIII(int[] stones) {
        int n = stones.length;
        dp = new int[n + 1][2];
        prefixStones = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            prefixStones[i] = prefixStones[i - 1] + stones[i - 1];
            dp[i - 1][0] = Integer.MAX_VALUE;
            dp[i - 1][1] = Integer.MIN_VALUE;
        }
        int answer = DP(0, n, 1, 1);
        // System.out.println(Arrays.deepToString(dp));
        return answer;
    }
}