class Solution {
    public int numberOfSubstrings(String s) {
        int l = 0; int r = 0;
        
        int[] abc = new int[] {0, 0, 0};
        long answer = (long) s.length() * (s.length() - 1) / 2;
        // System.out.println(answer);

        int m = -1;
        while (r < s.length())
        {
            abc[s.charAt(r) - 'a']++;
            if (abc[0] * abc[1] * abc[2] != 0)
            {
                if (m == -1)
                {
                    answer -= ((long) (r - l) * (r - l - 1) / 2);
                    // 얘는 오른쪽이 골라도됨 
                }
                else
                {
                    answer -= ((long)  (r - l) * (r - l - 1) / 2) - ((m - l) * (m - l - 1) / 2);
                }
                m = r;
            
                while (abc[0] * abc[1] * abc[2] != 0)
                {
                    abc[s.charAt(l) - 'a']--;
                    l++;
                    if (m == l)
                    {
                        m = -1;
                    }
                }
            }
            r++;
        }
        {
            if (m == -1)
            {
                answer -= ((long) (r - l) * (r - l - 1) / 2);
            }
            else
            {
                answer -= ((long) (r - l) * (r - l - 1) / 2) - ((m - l) * (m - l - 1) / 2);
            }
        }

        return (int) answer;

    }
}