class Solution {
    private int[] preChar;
    private int[][] DP;
    private String makeValidString(String s, int n)
    {
        StringBuffer sb = new StringBuffer();
        for (int i = 0, c = 0; i < s.length(); c++)
        {
            int k = 0;
            for (;k < preChar[c];)
            {
                sb.append(s.charAt(i + k++));
            }
            i += k;
            if ((n & 1) == 1 && i < s.length())
            {
                sb.append(s.charAt(i));
                // System.out.println(" 아래는 선별");
            }
            // System.out.println("문자열 인덱스 " + i  + " " + n + " 괄호 인덱스" + c) ;
            i++;
            n >>= 1;
        }
        // System.out.println();
        return sb.toString();
    }
    private boolean validParanthesis(String s, int n) {
        int l = 0;
        for (int i = 0, c = 0; i < s.length(); c++)
        {
            if ((n & 1) == 1)
            {
                // System.out.println(i);
                if (i + preChar[c] >= s.length())
                {
                    break;
                }
                if (s.charAt(i + preChar[c]) == '(')
                {
                    l++;
                }
                else
                {
                    l--;
                    if (l < 0)
                    {
                        return false;
                    }
                }
            }
            i += preChar[c] + 1;
            n >>= 1;
        }   

        return l == 0;
    }
    
    private List<String> dp(int n, int MAXIMUM, String s) {
        HashSet<String> lst = new HashSet<>();

        for (int i = 0; i < n; i++)
        {
            boolean flag = false;
            lst = new HashSet<>();
            for (int j = MAXIMUM; j >= 0; j--)
            {
                if (DP[i][j] == 0)
                {
                    continue;
                }

                if (validParanthesis(s, j))
                {
                    flag = true;
                    lst.add(makeValidString(s, j));
                    continue;
                }

                for (int k = 1; k <= j; k <<= 1)
                {
                    if ((k & j) == k)
                    {
                        DP[i + 1][k ^ j] = 1;
                    }
                }
            }
            if (flag)
            {
                return List.copyOf(lst);
            }
        }
        if (lst.isEmpty())
        {
            lst.add(makeValidString(s, 0));
        }
        return List.copyOf(lst);
    }
    public List<String> removeInvalidParentheses(String s) {
        int n = s.length();

        // 문자열이 제거된 인덱스에서 앞에 나올 문자들의 개수를 알려주는 것  
        // i번쨰 괄호 앞에 온다.
        preChar = new int[n];
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (
                s.charAt(i) != '(' &&
                s.charAt(i) != ')'
            )
            {
                preChar[i - j]++;
                j++;
            }
        }
        n-=j;
        int MAXIMUM = (1 << (n + 1)) - 1;
        // System.out.println(Arrays.toString(preChar) + " " + MAXIMUM + " " + s.length());
        // System.out.println(validParanthesis(s, MAXIMUM - (
        //     1 
        // )));
        DP = new int[n + 1][MAXIMUM + 1];
        DP[0][MAXIMUM] = 1;
        return dp(n, MAXIMUM, s);
    }
}