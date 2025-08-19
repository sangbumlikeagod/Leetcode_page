class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long q = 0;
        long answer = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] == 0)
            {
                q++;
            }
            else
            {
                if (q != 0)
                {
                    answer += (q * (q + 1)) / 2;
                }
                q = 0;
            }
        }
        if (q != 0)
        {
            answer += (q * (q + 1)) / 2;
        }
        
        return answer;
    }
}