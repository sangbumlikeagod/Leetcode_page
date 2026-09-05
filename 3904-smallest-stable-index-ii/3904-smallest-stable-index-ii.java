class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] M = new int[n];
        int[] m = new int[n];
        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            if (i == 0)
            {
                M[i] = nums[i];
                m[j] = nums[j];
            }
            else
            {
                M[i] = Math.max(nums[i], M[i - 1]);
                m[j] = Math.min(nums[j], m[j + 1]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (M[i] - m[i] <= k)
            {
                return i;
            }   
        }
        return -1;
    }
}