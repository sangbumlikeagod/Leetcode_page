class Solution {
    public long maximumTotalDamage(int[] power) {
        int n = power.length;
        Arrays.sort(power);
        ArrayList<Integer> key = new ArrayList<>();
        ArrayList<Long> value = new ArrayList<>();

        for (int i = 0; i < n; i++)
        {
            if (key.isEmpty() || key.get(key.size() - 1) != power[i])
            {
                key.add(power[i]);
                value.add((long) power[i]);
            }
            else
            {
                value.set(value.size() - 1, value.get(value.size() - 1) + power[i]);
            }
        }
        long[][] dp = new long[key.size() + 1][2];
        for (int i = 0; i < key.size(); i++)
        {
            int k = 1;
            dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][0]);
            dp[i][1] = dp[i][0] + value.get(i);
            while (i + k < key.size() && key.get(i) + 2 >= key.get(i + k))
            {
                k++;
            }
            dp[i + k][0] = Math.max(dp[i + k][0], dp[i][1]);
        }
        return dp[key.size()][0];
    }
}