class Solution {
    private int counts(int x)
    {
        int ret = 0;
        while (x > 0)
        {
            ret += ((x & 1) == 1) ? 1 : 0;
            x >>= 1;
        }
        return ret;
    }
    public int countPrimeSetBits(int left, int right) {
        
        int answer = 0;
        for (int i = left; i <= right; i++)
        {
            int ret = counts(i);
            if (ret == 2 || ret == 3 || ret == 5 || ret == 7 || ret == 11 || ret == 13 || ret == 17 || ret == 19)
            {
                answer++;
            }
        }
        return answer;
    }
}