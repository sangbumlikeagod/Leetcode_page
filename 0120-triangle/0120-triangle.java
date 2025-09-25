class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int m = triangle.size();
        int answer = Integer.MAX_VALUE;
        int[][] dp = new int[m + 1][m + 1];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][0] = triangle.get(0).get(0);
        
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // System.out.print(dp[i][j] + " ");
                dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + triangle.get(i + 1).get(j));
                dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], dp[i][j] + triangle.get(i + 1).get(j + 1));
            }
            // System.out.println();
        }

        for (int i = 0; i <= m - 1; i++)
        {
            answer = Math.min(answer, dp[m - 1][i]);
        }
        return answer;
    }
}