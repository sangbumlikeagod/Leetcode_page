class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int answer = 100001;
        int n = nums.size();
        for (int i = 0; i <= n - l; i++)
        {
            int preS = 0;
            for (int j = 0; j < l; j++)
            {
                preS += nums.get(i + j);
            }
            if (preS > 0)
            {
                answer = Math.min(answer, preS);
            }
            for (int j = l; j < r; j++)
            {

                if (i + j >= n) 
                {
                    break;
                }
                preS += nums.get(i + j);
                if (preS > 0)
                {
                    answer = Math.min(answer, preS);
                }
            }

        }
        return answer == 100001 ? -1 : answer;
    }
}