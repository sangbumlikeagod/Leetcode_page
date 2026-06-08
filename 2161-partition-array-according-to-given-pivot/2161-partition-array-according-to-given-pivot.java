class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        
        int n = nums.length;
        int l = 0, r = n - 1;

        int[] answer = new int[n];
        Arrays.fill(answer, pivot);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > pivot)
            {
                answer[r] = nums[i];
                r--;
            }
            else if (nums[i] < pivot)
            {
                answer[l] = nums[i];
                l++;
            }
        }
        r++;
        int r2 = n - 1;
        while (r < r2)
        {
            int tmp = answer[r];
            answer[r] = answer[r2];
            answer[r2] = tmp;
            r++; r2--;
        }
        

        return answer;
    }
}