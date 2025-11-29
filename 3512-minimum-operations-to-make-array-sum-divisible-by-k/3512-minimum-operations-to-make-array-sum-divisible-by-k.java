class Solution {
    public int minOperations(int[] nums, int k) {
        int answer = 0;
        for (int num : nums)
            {
                answer += num;
                answer %= k;
            }
        return answer;
    }
}