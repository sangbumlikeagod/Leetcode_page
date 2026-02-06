class Solution {
    public int minRemoval(int[] nums, int k) {
        
        Arrays.sort(nums);
        int answer = Integer.MAX_VALUE;
        int n = nums.length;
        for (int i = 0; i < answer; i++)
            {
                int l = i + 1;
                int r = n;
                while (l < r)
                {
                    int m = (l + r) / 2;
                    if (nums[m] <= (long) nums[i] * k)
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m;
                    }
                }
                
                answer = Math.min(answer, n - l + i);
            }
        return answer;
    }
    
}