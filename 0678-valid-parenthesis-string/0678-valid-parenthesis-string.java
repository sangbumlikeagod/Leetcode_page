class Solution {
    public boolean checkValidString(String s) {
        int wc = 0;
        int lc = 0;
        int rc = 0;
        for (char c : s.toCharArray())
        {
            if (c == '(')
            {
                lc++;
            }
            else if (c == ')') {
                if (lc != 0)
                {
                    lc--;
                }
                else if (wc != 0)
                {
                    wc--;
                }
                else
                {
                    return false;
                }
            }
            else {
                wc++;
            }
        }
        if (lc != 0 && wc < lc)
        {
            return false;
        }
        wc = 0;
        lc = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            char c = s.charAt(i);
            if (c == ')')
            {
                rc++;
            }
            else if (c == '(') {
                if (rc != 0)
                {
                    rc--;
                }
                else if (wc != 0)
                {
                    wc--;
                }
                else
                {
                    return false;
                }
            }
            else {
                wc++;
            }
        }

        return rc == 0? true : wc >= rc;
    }
}