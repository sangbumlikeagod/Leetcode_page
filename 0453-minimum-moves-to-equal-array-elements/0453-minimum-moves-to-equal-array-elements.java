class Solution {
    public int minMoves(int[] nums) {
        int n = nums.length;
        long prefixSum = 0;

        int minV = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];
            minV = Math.min(minV, nums[i]);
        }
        return (int) (prefixSum - (long) minV * n);
    }
}