class Solution {
    public int minCost(String colors, int[] neededTime) {
        char lasts = ' ';
        int maxs = 0;
        int sums = 0;
        int n = neededTime.length;
        int answer = 0;
        for (int i = 0; i <= n; i++)
            {
                char c = i == n ? ' ' : colors.charAt(i);
                int val = i == n ? 0 : neededTime[i];
                if (c == lasts)
                {
                    sums += val;
                    maxs = Math.max(maxs, val);
                }
                else
                {
                    answer += sums - maxs;
                    lasts = c;
                    sums = val;
                    maxs = val;
                }
            }
        return answer;
    }
}