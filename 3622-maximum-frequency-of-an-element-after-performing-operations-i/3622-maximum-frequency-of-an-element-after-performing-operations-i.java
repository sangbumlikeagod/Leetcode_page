class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        Arrays.sort(nums);
        int l = 0, m = 1, r = 1, l2 = 0, r2 = 1, r3 = 1, l3 = 0;
        int n = nums.length;
        int answer = 1;
        while(m < n)
        {
            while (r3 < n && nums[r3] <= nums[l2] + 2 * k)
            {
                r3++;
            }
            while(r2 < n && nums[r2] <= nums[m] + k)
            {
                r2++;
            }
            while(r < r2 && nums[r] == nums[m])
            {
                r++;
            }

            while (l < m && nums[l] != nums[m])
            {
                l++;
            }
            while (l2 < l && nums[l2] + k < nums[m])
            {
                l2++;
            }
            while (l3 < l2 && nums[l3] + 2 * k < nums[m])
            {
                l3++;
            }

            answer = Math.max(answer, (r - l) + Math.min(numOperations, r2 - r +  l - l2) + Math.max(0, Math.min(numOperations - 1 - (r2 - r +  l - l2), (l2 - l3 + r3 - r2))));
            // System.out.println("(" + l3 + ", " + + l2 + ", " + l + ", "+ m + ", " + r + ", "+  r2+", " + r3 + ")");
            // System.out.println(answer + " " +  (l2 - l3 + r3 - r2) + " " + (numOperations - 1 - (r2 - r +  l - l2)) + " " +  (r - l));
            // System.out.println(Math.min(numOperations, r2 - r +  l - l2));
            // System.out.println(Math.max(0, Math.min(numOperations - 1 - (r2 - r +  l - l2), (l2 - l3 + r3 - r2))));
            // System.out.println((r - l) + Math.min(numOperations, r2 - r +  l - l2) + Math.max(0, Math.min(numOperations - 1 - (r2 - r +  l - l2), (l2 - l3 + r3 - r2))));
            m++;
        }
        return answer;
    }
}