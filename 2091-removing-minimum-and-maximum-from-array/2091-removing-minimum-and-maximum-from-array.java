class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;
        int m = 100001; int mi = -1;
        int M = -100001; int Mi = -1;


        for (int i = 0; i < n; i++)
        {
            if ( nums[i] < m)
            {
                m = nums[i];
                mi = i;
            }
            if (nums[i] > M)
            {
                M = nums[i];
                Mi = i;
            }        
        }
        // n - 
        int answer = Math.max(mi + 1, Mi + 1);
        answer = Math.min(answer, Math.max(
            n - mi, n - Mi
        ));

        answer = Math.min(
            answer, 
            mi + 1 + n - Mi
        );
        answer = Math.min(
            answer, 
            Mi + 1 + n - mi
        );
        return answer;
    }
}