class Solution {
    public int findFinalValue(int[] nums, int original) {
        int n = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < original)
            {
                continue;
            }
            else if (nums[i] == original)
            {
                original <<= 1;
            }
            else
            {
                return original;
            }
        }
        return original;
    }
}