class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length;
        long[] prefixSum = new long[n + 1];
        long[] suffixSum = new long[n + 1];
        Arrays.sort(nums);
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] +
            (nums[i] - (i == 0 ? 0 : nums[i - 1])) * (i);

            suffixSum[n - 1 - i] = suffixSum[n - i] + 
            ((i == 0 ? nums[n - 1 - i] : nums[n - i]) - nums[n - 1 - i]) * (i);
        }
        // System.out.println(Arrays.toString(prefixSum));
        // System.out.println(Arrays.toString(suffixSum));
        long answer = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
        {
            answer =Math.min(prefixSum[i + 1]+ suffixSum[i], answer);
        }
        return (int) answer;
    }
}