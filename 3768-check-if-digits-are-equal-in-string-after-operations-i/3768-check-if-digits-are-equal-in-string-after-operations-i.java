class Solution {
    public boolean hasSameDigits(String s) {
        int n = s.length();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
        {
            nums[i] = s.charAt(i) - '0';
        }
        for (int j = 1; j < n - 1; j++)
        {
            for (int i = 0; i < n - j; i++)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0] == nums[1];
    }
}