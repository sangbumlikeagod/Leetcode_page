class Solution {
    public int[] leftRightDifference(int[] nums) {
        int l = 0;
        int n = nums.length;

        Integer r = Arrays.stream(nums).reduce(0, Integer::sum);
        int[] answer = new int[n];

        for (int i = 0; i < n; i++)
        {
            r -= nums[i];
            answer[i] = Math.abs(l - r);
            l += nums[i];
        }
        return answer;
    }
}