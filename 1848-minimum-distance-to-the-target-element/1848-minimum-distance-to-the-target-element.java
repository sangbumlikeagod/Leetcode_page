class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int l = start;
        int r = start;
        int answer = 0;
        while (l >= 0 || r < nums.length)
        {
            if (nums[l] == target || nums[r] == target)
            {
                return answer;
            }
            if (l > 0)
            {
                l--;   
            }
            if (r < nums.length - 1)
            {
                r++;
            }
            answer++;
        }

        return answer;
    }
}