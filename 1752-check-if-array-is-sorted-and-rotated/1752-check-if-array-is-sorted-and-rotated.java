class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int revCount = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                revCount++;
            }
        }
        if (revCount == 0)
        {
            return true;
        }
        else if (revCount == 1)
        {
            return nums[n - 1] <= nums[0];
        }
        return false;
    }
}