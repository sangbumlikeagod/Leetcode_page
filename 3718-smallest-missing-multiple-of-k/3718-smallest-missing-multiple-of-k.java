class Solution {
    public int missingMultiple(int[] nums, int k) {
        int n = nums.length;
        int[] aaaa = new int[102];

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % k == 0)
            {
                aaaa[nums[i] / k]++;
            }
        }
        for (int i = 1; i < 101; i++)
        {
            if (aaaa[i] == 0)
            {
                return k * i; 
            }
        }
        return k * 101;
    }
}