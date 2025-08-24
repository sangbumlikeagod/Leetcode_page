class Solution {
    private int idx = 0;
    private boolean nonzero = true;
    private int init_start(int[] nums)
    {
        int answer = 0;
        while (idx < nums.length)
        {
            answer = Math.max(answer, start(nums));
        }
        return nonzero ? answer - 1 : answer; 
    }
    private void skip(int[] nums)
    {
        while (idx < nums.length && nums[idx] == 0)
        {
            idx++;
        }
    }
    private int start(int[] nums)
    {
        int ret = 0;
        int curr = 0;
        int before = 0;
        for (; idx < nums.length; idx++)
        {
            if (nums[idx] == 1)
            {
                curr++;
            }
            else
            {
                nonzero = false;
                if (idx != 0 && nums[idx - 1] == 0)
                {
                    skip(nums);   
                    break;
                }
                // if (before == 0)
                // {
                //     ret = Math.max(ret, curr - 1);   
                // }
                // else
                // {
                //     ret = Math.max(ret, curr + before);
                // }
                ret = Math.max(ret, curr + before);
                before = curr;
                curr = 0;
            }
        }

        ret = Math.max(ret, curr + before);
        return ret;
    }
    public int longestSubarray(int[] nums) {
        return init_start(nums);
    }
}