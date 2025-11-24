class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        int n = nums.length;
        int total = 0;
        List<Boolean> answer = new LinkedList<>();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                total++;
            }
            answer.addLast(total % 5 == 0);
            total <<= 1;
            total %= 10;
        }
        return answer;
    }
}