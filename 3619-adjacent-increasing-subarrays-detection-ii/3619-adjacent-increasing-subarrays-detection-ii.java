class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int n = nums.size();
        int[] increasing = new int[n];
        for (int i = 0; i < n; i++)
        {
            increasing[i] = 1;
        }
        int answer = 1;
        for (int i = 1; i < n; i++)
        {
            
            if (nums.get(i) > nums.get(i - 1))
            {
                increasing[i] = increasing[i - 1] + 1;
                answer = Math.max(answer, increasing[i] / 2);
                if (i >= increasing[i] && increasing[i - increasing[i]] >= increasing[i])
                {
                    answer = Math.max(answer, increasing[i]);
                }
            }
        }
        // System.out.println(Arrays.toString(increasing));
        return answer;
    }
}