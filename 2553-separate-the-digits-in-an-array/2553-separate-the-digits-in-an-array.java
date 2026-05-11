class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> answers = new ArrayList<>();
        int n = nums.length;
        for (int i = n - 1; i >= 0; i--)
        {
            while (nums[i] > 0)
            {
                answers.add(nums[i] % 10);
                nums[i] /= 10;
            }
        }
        answers = answers.reversed();
        int[] answer = answers.stream().mapToInt(Integer::intValue).toArray();

        return answer;
    }
}