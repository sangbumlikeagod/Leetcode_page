class Solution {
    private int arrrrr(int a, int b) {
        return Math.abs(a) - Math.abs(b);
    }
    public long maxAlternatingSum(int[] nums) {
        long answer = 0;
        int n = nums.length;
        Integer[] boxed = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        Arrays.sort(
            boxed,
            this::arrrrr
        );

        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
            {
                answer -= (long) boxed[i] * boxed[i];
            }
            else
            {
                answer += (long) boxed[i] * boxed[i];
            }
        }

        return answer;
    }
}