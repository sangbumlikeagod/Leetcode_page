class Solution {
    public int triangularSum(int[] nums) {

        int[] p_nums = nums;
        for (int i = 1; i < nums.length; i++)
            {
                int[] nP_nums = new int[nums.length];
                for (int j = 0; j < nums.length - i; j++)
                     {
                        nP_nums[j] = (p_nums[j] + p_nums[j + 1]) % 10;
                     }
                p_nums = nP_nums;
            }
        return p_nums[0];
    }
}