class Solution {
    public int maxRotateFunction(int[] nums) {
        int total = 0, n = nums.length;
        for (int num : nums)
        {
            total += num;
        }
         
        int query = 0;
        for (int idx = 0; idx < n; idx++)
        {
            query += idx * nums[idx];
        }

        int answer = query;
        for (int i = 0; i < n; i++)
        {
            query -= total;
            query += (n) * nums[i];
            answer = Math.max(answer, query);
        }
        return answer;
        
    }
}