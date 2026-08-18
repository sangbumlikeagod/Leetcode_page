class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        int[] args = new int[51];

        for (int i = 0, r = k - 1; i <= n - k; i++, r++)
        {
            int[] visited = new int[51];
            for (int j = i; j <= r; j++)
            {  
                if (visited[nums[j]] == 0)
                {
                    args[nums[j]]++;
                    visited[nums[j]] = 1;
                }
            }
        }
        int answer = -1;
        for (int i = 0; i <= 50; i++)
        {
            if (args[i] == 1)
            {
                answer = Math.max(answer, i);
            }
        }
        return answer;
    }
}