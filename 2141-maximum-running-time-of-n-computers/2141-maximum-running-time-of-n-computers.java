
class Solution {
    private int binarySearch(long target, long[] prefixSum){
        int i = 0, j = prefixSum.length;
        while(i < j)
        {
            int m = (i + j) / 2;
            if (prefixSum[m] < target)
            {
                // 얘는 답일 수 없음
                i = m + 1;
            }
            else
            {
                j = m;
            }
        }
        return i;
    }


    public long maxRunTime(int n, int[] batteries) {
        long maxi = 0;
        for (int battery : batteries)
        {  
            maxi += battery;
        }
        maxi /= n;
        long mini = 1;

        // for (int i = bl - 1; i >= 0; i--)
        // {
        //     prefixSum[bl - i] = prefixSum[bl - i - 1] + batteries[i];
        // }
        while (mini < maxi)
        {
            long middle = (mini + maxi) / 2 + (mini + maxi) % 2;
            long tmp = 0;
            for (int batterry : batteries)
            {
                tmp += Math.min(middle, batterry);
            }
            if (tmp >= (n * middle))
            {
                mini = middle;
            }
            else
            {
                maxi = middle - 1;
            }
        }
        return mini;
        


    }
}