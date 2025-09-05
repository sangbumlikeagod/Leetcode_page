class Solution {
    private long MAXIMUM = ((long) 1 << 61);
    private int getMinimum(long num) {
        int ret = 0;
        while (num > 0)
        {
            ret += (num & 1);
            num >>= 1;
        }
        return ret;
    }
    public int makeTheIntegerZero(int num1, int num2) {
        int answer = -1;
        long num11 = num1;
        int cnt = 0;
        while (num11 > 0)
        {
            num11 -= num2;
            cnt++;
            if (num11 < 0)
            {
                break;
            }
            if (getMinimum(num11) <= cnt && cnt <= num11)
            {
                answer = cnt;
                break;
            }
            if (num11 >= MAXIMUM) break;
        }
        return answer;
    }
}