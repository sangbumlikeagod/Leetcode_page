class Solution {
    public int findGCD(int[] nums) {
        int MAXIMUM = 0;
        int MINIMUM = 1000;
        for (int num : nums)
        {
            MAXIMUM = Math.max(MAXIMUM, num);
            MINIMUM = Math.min(MINIMUM, num);
        }
        while (MINIMUM != 1 && MAXIMUM % MINIMUM != 0)
        {
            MAXIMUM = MAXIMUM % MINIMUM;
            int tmp = MAXIMUM;
            MAXIMUM = MINIMUM;
            MINIMUM = tmp; 
        } 
        return MINIMUM;
    }
}