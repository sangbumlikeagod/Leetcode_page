class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int answer = Integer.MIN_VALUE;
        int l = energy.length;
        int[] dp = new int[l];
        for (int i = 0; i < l; i++)
        {
            if (i + k < l)
            {
                dp[i + k] = Math.max(dp[i + k], dp[i] + energy[i]);
            }
            else
            {
                answer = Math.max(answer, dp[i] + energy[i]);
            }
        }
        return answer;
    }
}