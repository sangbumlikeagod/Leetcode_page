class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[][] dp = new int[m + 1][n + 1];

        for (int i =0; i < m; i ++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums1[i] * nums2[j] > 0)
                {
                    dp[i + 1][j + 1] = Math.max(dp[i + 1][j + 1], dp[i][j] + nums1[i] * nums2[j]);
                }
                dp[i + 1][j] = Math.max(dp[i + 1][j], dp[i][j]);
                dp[i][j + 1] = Math.max(dp[i][j + 1], dp[i][j]);
            }
        }

        int answer = dp[m][n];
        for (int i = 0; i <= m; i++)
        {
            // System.out.println(Arrays.toString(dp[i]));
            answer = Math.max(answer, dp[i][n]);
        }
        for (int i = 0; i <= n; i++)
        {
            answer = Math.max(answer, dp[m][i]);
        }
        if (answer == 0) {
            int maxNegativeeNums1 = Integer.MIN_VALUE;
            int minPositiveNums1 = Integer.MAX_VALUE;

            int maxNegativeeNums2 = Integer.MIN_VALUE;
            int minPositiveNums2 = Integer.MAX_VALUE;
            for (int num : nums1)
            {
                if (num >= 0)
                {
                    minPositiveNums1 = Math.min(minPositiveNums1, num);
                }
                if (num <= 0)
                {
                    maxNegativeeNums1 = Math.max(maxNegativeeNums1, num);
                }
            }
            for (int num : nums2)
            {
                if (num >= 0)
                {
                    minPositiveNums2 = Math.min(minPositiveNums2, num);
                }
                if (num <= 0)
                {
                    maxNegativeeNums2 = Math.max(maxNegativeeNums2, num);
                }
            }
            answer = Math.max(minPositiveNums2 * maxNegativeeNums1, minPositiveNums1 * maxNegativeeNums2);
        }
        return answer;

    }
}