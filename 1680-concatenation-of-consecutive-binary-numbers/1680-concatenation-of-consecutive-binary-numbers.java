class Solution {
    private StringBuffer privateGetS(int n)
    {
        StringBuffer sb = new StringBuffer();
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                sb.append('1');
            }
            else
            {
                sb.append('0');
            }
            n >>= 1;
        }
        return sb;
    }

    public int concatenatedBinary(int n) {
        long MODULO = (long) 1e9 + 7;
        
        long answer = 0;

        StringBuffer sb = new StringBuffer();
        while (n > 0)
        {
            StringBuffer mSb = privateGetS(n--);
            sb.append(mSb);
        }
        System.out.println();
        for (int i = sb.length() - 1; i >= 0; i--)
        { 
            answer <<= 1;
            if (sb.charAt(i) == '1')
            {
                answer |=  1;   
            }
            answer %= MODULO;
        }
        
        return (int) (answer % MODULO);
    }
}