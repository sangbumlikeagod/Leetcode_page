class Solution {
    private int upper_bound(int[] nums, int l, int r, int target)
    {
        while (l < r)
            {
                int m = (l + r) / 2 + (l + r) % 2;
                if (nums[m] >= target)
                {
                    r = m - 1;
                }
                else
                {
                    l = m;
                }
            }
        return l;
    }
    
    public int triangleNumber(int[] nums) {
        int answer = 0;
        Arrays.sort(nums);        

        for (int i = 0; i < nums.length; i++)
        {   
            if (nums[i] == 0) continue;
            for (int j = i + 1; j < nums.length - 1; j++)
            {
                if (nums[j] == 0) continue;
                int idx = upper_bound(nums, j, nums.length - 1, nums[i] + nums[j]);
                // System.out.println(i + " " + j + " " + idx);
                answer += idx - j;
            }
        }

        return answer;
    }
}