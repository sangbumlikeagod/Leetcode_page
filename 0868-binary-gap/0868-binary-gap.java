class Solution {
    public int binaryGap(int n) {
        int answer = 0;

        int dst = -1;
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                answer = Math.max(answer,dst);
                dst = 1;
            }
            else if (dst != -1)
            {
                dst++;
            }
            n >>= 1;
        }

        return answer;
    }
}