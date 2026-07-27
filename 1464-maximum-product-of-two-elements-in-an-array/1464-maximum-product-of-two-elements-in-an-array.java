class Solution {
    public int maxProduct(int[] nums) {
        int f = 0, s = 0;
        for (int num : nums)
        {
            if (num > f)
            {
                s = f;
                f = num;
            }
            else if (num > s)
            {
                s = num;
            }
        }   
        return (f - 1) * (s - 1);
    }
}