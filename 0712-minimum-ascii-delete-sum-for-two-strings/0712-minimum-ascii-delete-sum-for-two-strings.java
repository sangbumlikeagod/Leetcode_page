class Solution {

    private int getAsciiSum(String s)
    {
        int ret = 0;
        for (char c : s.toCharArray())
        {
            ret += c;
        }
        return ret;
    }
    public int minimumDeleteSum(String s1, String s2) {
        int[][] dp = new int[1001][1001];
        int s1l = s1.length();
        int s2l = s2.length();


        for (int i = 0; i <= s1l; i++)
        {
            for (int j = 0; j <= s2l; j++)
            {
                if (i != s1l && j != s2l && s1.charAt(i) == s2.charAt(j))
                {
                    dp[i + 1][j + 1] = Math.max(dp[i + 1][j + 1], dp[i][j] + (int) s1.charAt(i) + (int) s2.charAt(j));
                }
                else
                {
                    if (j != s2l)
                    {
                        dp[i ][j + 1] = Math.max(dp[i][j + 1], dp[i][j]);   
                    }
                    if (i != s1l)
                    {
                        dp[i + 1][j] = Math.max(dp[i + 1][j], dp[i][j]);   
                    }
                }
            }
        }
        return getAsciiSum(s1) + getAsciiSum(s2) - dp[s1l][s2l];
    }
}