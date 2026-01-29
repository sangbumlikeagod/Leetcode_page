class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        long[][] dp = new long[26][26];
        int n = original.length;

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (i != j)
                {
                    dp[i][j] = Long.MAX_VALUE;
                }
            }
        }
        for (int k = 0; k < 26; k++)
        {

            for (int i = 0; i < n; i++)
            {
                int from = original[i] - 'a';
                int to = changed[i] - 'a';
                long cst = cost[i];

                for (int j = 0; j < 26; j++)    
                {
                    if (dp[j][from] != Long.MAX_VALUE)
                    {
                        dp[j][to] = Math.min(dp[j][to], dp[j][from] + cst);
                    }
                }
            }
        }

        long answer = 0;
        for (int i = 0; i < target.length(); i++)
        {
            if(dp[source.charAt(i) - 'a'][target.charAt(i) - 'a'] == Long.MAX_VALUE)
            {
                return -1;
            }
            answer += dp[source.charAt(i) - 'a'][target.charAt(i) - 'a']; 
        }
        return answer;
    }
}