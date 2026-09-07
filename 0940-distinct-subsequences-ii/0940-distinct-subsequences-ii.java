class Solution {
    private Integer MODULO = (int) 1e9 + 7;
    public int distinctSubseqII(String s) {
        int n = s.length();
        int[] latest_show = new int[26];
        int[] latest_close = new int[n];
        Arrays.fill(latest_show, -1);
        for (int i = 0; i < n; i++)
        {
            char c = s.charAt(i);
            latest_close[i] = latest_show[c - 'a'];
            latest_show[c - 'a'] = i;
        }
        // System.out.println(Arrays.toString(latest_close));
        int[] dp = new int[n];
        // 만약 그 값이 -1
        for (int i = 0; i < n; i++)
        {
            if (latest_close[i] == -1)
            {
                dp[i]++;
                latest_close[i] = 0;
            }
            long tmp = 0;
            for (int j = latest_close[i]; j < i; j++)
            {
                tmp += dp[j];
                tmp %= MODULO;
            }
            dp[i] += (int) tmp; 
            dp[i] %= MODULO;
        }
        long answer = 0;

        for (int i = 0; i < n; i++) 
        {
            answer += dp[i];
            answer %= MODULO;
        }
        return (int) answer;
    }
}