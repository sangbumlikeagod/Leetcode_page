class Solution {
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++)
        {
            int tmp = 0;
            while (nums[i] > 0)
            {
                tmp += nums[i] % 10;
                nums[i] /= 10;
            }
            if (tmp == i)
            {
                return i;
            }
        }
        return -1;
    }
}