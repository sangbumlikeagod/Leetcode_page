class Solution {
    public String removeOuterParentheses(String s) {
        StringBuffer sb = new StringBuffer();
        String answer = "";
        int l = 0;
        for (char c : s.toCharArray())
        {
            if (c == '(')
            {
                l++;
            }
            else
            {
                l--;
            }
            sb.append(c);

            if (l == 0)
            {
                answer = answer.concat(
                    sb.substring(1, sb.length() - 1
                ));
                sb = new StringBuffer();
            }
        }
        return answer;
    }
}