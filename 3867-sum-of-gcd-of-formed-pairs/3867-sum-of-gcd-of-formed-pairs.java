class Solution {
    private int findGDC(int a, int b) {
        if (a < b)
        {
            int tmp = b;
            b = a;
            a = tmp;
        }
        while (a != 1 && b != 1 && a % b != 0)
        {
            a %= b;
            int tmp = b;
            b = a;
            a = tmp;
        }
        return b;
    }
    public long gcdSum(int[] nums) {
        long answer = 0;
        int x = 0;
        int n = nums.length;
        int[] xx = new int[n];
        for (int i = 0; i < n; i++)
        {
            x = Math.max(nums[i], x);
            xx[i] = findGDC(x, nums[i]);

        }
        Arrays.sort(xx);
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            answer += findGDC(xx[i], xx[j]);
        }

        return answer;
    }
}