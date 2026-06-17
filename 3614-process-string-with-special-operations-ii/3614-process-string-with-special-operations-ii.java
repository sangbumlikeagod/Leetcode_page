class Solution {
    public char processStr(String s, long k) {
        int n = s.length();

        long lent = 0; 
        boolean reversed = false;

        for (char c : s.toCharArray())
        {
            if (c == '#')
            {
                lent <<= 1;
            }
            else if (c == '*')
            {
                if (lent > 0)
                {
                    lent -= 1;
                }
            }
            else if (c == '%')
            {
                if (lent > 1)
                {
                    reversed = !reversed;
                }
            }
            else
            {
                lent += 1;
            }
        }
        if (k >= lent)
        {
            return '.';
        }

        long pLent = lent;
        long pPos = k + 1;
        for (int i = n - 1; i >= 0; i--)
        {
            char c = s.charAt(i);
            // System.out.println(pPos + " " + pLent + " " + reversed);

            // 현재 n개가 있는데 
            if (c == '%')
            {
                reversed = !reversed;
                pPos = pLent - pPos + 1;
            }
            else if (c == '#')
            {
                pLent /= 2;
                if (pPos > pLent)
                {
                    pPos -= pLent;
                }
            }
            else if (c == '*')
            {
                pLent++;
            }
            else if ('a' <= c && c <= 'z')
            {
                if (pPos == pLent)
                {
                    return c;
                }
                // if (reversed && pPos == 1)
                // {
                //     return c;
                // }
                // else if (!reversed && pPos == pLent)
                // {
                //     return c;
                // }
                pLent--;
                // k가 얘인지를 비교한다
            }
        }
        // lent가 끝
        // System.out.println(lent);

        return 'a';

        
    }
}