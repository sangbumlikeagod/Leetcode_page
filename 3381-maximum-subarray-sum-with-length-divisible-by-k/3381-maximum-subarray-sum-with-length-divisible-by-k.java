class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;

        long[] prefixSum = new long[n + 1];

        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        // System.out.println(Arrays.toString(prefixSum));
        long[] basics = new long[n];
        long answer = Long.MIN_VALUE;
        
        for (int i = 0; i < n; i++)
            {
                basics[i] = (long) -1e15;
                if (i >= k - 1)
                {
                    long myValue = prefixSum[i + 1] - prefixSum[i + 1 - k];
                    basics[i] = Math.max(basics[i], myValue);
                    if (i >= k)
                    {
                        basics[i] = Math.max(
                            basics[i - k] + myValue, 
                            basics[i]
                        );
                    }
                    answer = Math.max(answer, basics[i]);
                }
            }

        return answer;
        // answer = Math.max(answer, candidates);
        // return answer;
    }
}