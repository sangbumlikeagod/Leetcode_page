class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {

        List<Integer> answer = new ArrayList<>();
        int before = 0;
        int me = 0;
        for (int num : nums)
        {
            if (num < target)
            {
                before++;
            }
            else if (num == target)
            {
                me++;
            }
        }
        while (me > 0)
        {
            answer.add(before++);
            me--;
        }
        return answer;
    }
}