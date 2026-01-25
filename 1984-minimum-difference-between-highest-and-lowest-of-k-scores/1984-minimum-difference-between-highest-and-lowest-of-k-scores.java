class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i <= n - k; i++)
        {
            answer = Math.min(answer, nums[i + k - 1] - nums[i]);
        }
        return answer;
    }
}