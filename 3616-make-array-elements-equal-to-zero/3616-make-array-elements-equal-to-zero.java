class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int answer = 0;
        int ttmp = 0;
        for (int i = 0; i < n; i++)
        {
            ttmp += nums[i];
        }

        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            tmp += nums[i];
            if (nums[i] == 0)
            {
                if (Math.abs(ttmp - 2 * tmp) <= 1)
                {
                    if (ttmp % 2 == 1)
                    {
                        answer++;
                    }
                    else
                    {
                        answer += 2;
                    }
                }
            }
        }
        return answer;

    }
}