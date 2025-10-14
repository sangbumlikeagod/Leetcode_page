class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();
        int[] increasings = new int[n];
        if (k == 1)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            increasings[i] = 1;
        }
        increasings[0] = 1;
        for (int i = 1; i < n; i++)
        {
            
            if (nums.get(i - 1) < nums.get(i))
            {
                increasings[i] = increasings[i - 1] + 1;
                if (increasings[i] >= k)
                {
                    if (i >= k && increasings[i - k] >= k)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}