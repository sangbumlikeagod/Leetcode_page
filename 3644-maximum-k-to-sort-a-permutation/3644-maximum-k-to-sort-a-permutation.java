class Solution {
    public int sortPermutation(int[] nums) {
        int n = nums.length; 
        int answer = (1 << 20) - 1;
        for (int i = 0; i < n; i++)
        {
            if (i != nums[i])
            {
                answer &= i;
            }
        }
        return answer == (1 << 20) - 1 ? 0 : answer ;
    }
}