class Solution {
    public int reverseBits(int n) {
        int answer= 0;
        int digits = 0;
        while (n > 0) 
        {
            if ((n & 1) == 1)
            {
                answer |= 1;
            }
            answer <<= 1;
            n >>= 1;
            digits++;
        }
        // System.out.println("\n" + digits);
        while (32 - digits > 1)
        {
            answer <<= 1;
            digits++;
        }
        return answer;

    }
}