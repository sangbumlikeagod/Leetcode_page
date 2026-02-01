class Solution {
    public int minimumCost(int[] nums) {
        int[] minim = new int[2];
        minim[0] = Integer.MAX_VALUE;
        minim[1] = Integer.MAX_VALUE;
        int n = nums.length;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < minim[0])
            {
                minim[1] = minim[0];
                minim[0] = nums[i];
            }
            else if (nums[i] < minim[1])
            {
                minim[1] = nums[i];
            }
        }
        return nums[0] + minim[0] + minim[1];
    }
}