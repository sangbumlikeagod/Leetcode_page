class Solution {
    public boolean isGood(int[] nums) {
        Arrays.sort(nums);
        int k = 1, n = nums.length - 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != k)
            {
                return false;
            }
            k++;
        }
        if (nums[n] != k - 1) return false;
        return true;
    }
}