class Solution {
    public boolean isTrionic(int[] nums) {
        int quota = 2;
        if (nums[0] >= nums[1]) return false;
        for (int i = 2; i < nums.length; i++)
        {
            int dx = (nums[i] - nums[i - 1]) * (nums[i - 1] - nums[i - 2]);
            if (dx < 0)
            {
                quota--;
            }
            else if (dx == 0)
            {
                return false;
            } 
        }
        return quota == 0;
    }
}