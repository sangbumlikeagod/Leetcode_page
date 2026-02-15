class Solution {



    public String addBinary(String a, String b) {
        
        int l = Math.max(a.length(), b.length());

        int[] buffer = new int[10001];
        for (int i = a.length() - 1, j = 0; i >= 0; i--, j++)
        {
            buffer[10000 - j] += a.charAt(i) == '0' ? 0 : 1;
        }
        for (int i = b.length() - 1, j = 0; i >= 0; i--, j++)
        {
            buffer[10000 - j] += b.charAt(i) == '0' ? 0 : 1;
        }
        


        for (int i = l , j = 0; i >= 0; i--, j++)
        {
            if (buffer[10000 - j] >= 2)
            {
                buffer[10000 - j - 1]++;
                buffer[10000 - j] -= 2;
            }
        }

        StringBuffer sb = new StringBuffer();
        if (buffer[10000 - l] == 1)
        {
            sb.append('1');
        }

        for (int i = l - 1; i >= 0; i--)
        {
            char next = buffer[10000 - i] == 0? '0' : '1';
            sb.append(next);
        }

        return sb.toString();
    }
}