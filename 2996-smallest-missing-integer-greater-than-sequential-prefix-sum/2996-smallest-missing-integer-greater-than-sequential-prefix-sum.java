class Solution {
    public int missingInteger(int[] nums) {
        int[] x = new int[1500];
        int n = nums.length;
        int sums = nums[0];
        int going = 1;
        
        for (int i = 1; i < n; i++)
        {
            if (
                going == 1 &&
                nums[i] == nums[i - 1] + 1)
            {
                sums += nums[i];
            }
            else
            {
                going = 0;
                x[nums[i]] = 1;
            }
        }
        if (sums == nums[0])
        {
            x[sums] = 1; 
        }
        for (int i = sums; i < 1500; i++)
        {
            if (x[i] == 0)
            {
                return i;
            }
        }
        return 1500;
    }
}