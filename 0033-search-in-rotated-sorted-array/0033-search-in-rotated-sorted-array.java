class Solution {

    private int skewedIndex(int[] nums)
    {
        int l = 0;
        int r = nums.length - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] > nums[nums.length - 1])
            {
                l = m + 1;
            }
            else if (nums[m] < nums[nums.length - 1])
            {
                r = m;
            }
            else
            {
                return m;
            }
        }
        return l;
    }

    private int doubleIndex(int[] nums, int startIdx, int target)
    {
        int l = startIdx;
        // System.out.println(l);

        int n = nums.length;
        int r = l == 0 ? n - 1 : l - 1 + n;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m % n] < target)
            {
                l = m + 1;
            }
            else if (nums[m % n] == target)
            {
                return m % n;
            }
            else
            {
                r = m - 1;
            }
        }
        return l % n;
    }
    public int search(int[] nums, int target) {
        // int n = nums.length;

        int startIdx = skewedIndex(nums);
        int ans = doubleIndex(nums, startIdx, target);
        // System.out.println(startIdx + " " + ans);
        return nums[ans] == target ? ans : -1;
    }
}