class Solution {
    public int minimumCost(int[] cost) {
        // 두개중 작은애보다 작은애 하나 산다.
        Arrays.sort(cost);
        int n = cost.length;
        int answer = 0;
        for (int i = n - 1; i >= 0;)
        {
            answer += cost[i--];
            if (i >= 0)
            {
                answer += cost[i--];
            }
            if (i >= 0)
            {
                i--;
            }
        }
        return answer;
    }
}