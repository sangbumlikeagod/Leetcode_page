class Solution {
    private int MODULO = (int) 1e9 + 7;
    private void prefixSum(int[] mat, boolean notReversed) {
        int l = mat.length;

        if (notReversed)
        {
            for (int i = 0; i < l - 2; i++)
            {
                mat[i + 1] += mat[i];
                mat[i + 1] %= MODULO;
            }
        }
        else
        {
            for (int i = l - 1; i > 1; i--)
            {
                mat[i - 1] += mat[i];
                mat[i - 1] %= MODULO;
            }
        }
    }
    public int zigZagArrays(int n, int l, int r) {
        int ll = r - l + 1;
        int[][][] dp = new int[n + 1][2][ll + 2];
        int answer = 0;


        Arrays.fill(dp[0][0], 1);
        Arrays.fill(dp[0][1], 1);
        dp[0][0][ll + 1] = 0;
        dp[0][0][0] = 0;
        dp[0][1][ll + 1] = 0;
        dp[0][1][0] = 0;
        prefixSum(dp[0][0], false);
        prefixSum(dp[0][1], true);
        // 0은 prefix상 존재하는것이고 1이 최저다 
        for (int i = 0; i < n; i++)
        {
            // 이전값 상승부터 
            for (int k = 2; k <= ll; k++)
            {
                int mein = dp[i][0][k];
                // 다음 하락인 애들한테 
                dp[i + 1][1][k - 1] += mein;
                dp[i + 1][1][k - 1] %= MODULO;
            }
            // 이전값 하락
            for (int k = 0; k < ll; k++)
            {
                int mein = dp[i][1][k];
                // 상승할 애들한테
                dp[i + 1][0][k + 1] += mein;
                dp[i + 1][0][k + 1] %= MODULO;
            }
            prefixSum(dp[i + 1][0], false);
            prefixSum(dp[i + 1][1], true);
        }
        

        return (dp[n - 1][0][1] + dp[n - 1][1][ll]) % MODULO;
    }
}