class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int n = happiness.length;
        Arrays.sort(happiness);
        long answer = 0;
        for (int i = n - 1; i > n - 1 - k; i--)
        {
            answer += Math.max(0, happiness[i] - (n - 1 - i));
        }
        return answer;
    }
}