class Solution {
    public long maxTotalValue(int[] nums, int k) {
        long minN = (long) 1e9 + 7;
        long maxN = 0;
        for (int num : nums)
        {
            maxN = Math.max(maxN, num);
            minN = Math.min(minN, num);
        }
        return (maxN - minN) * k;
    }
}