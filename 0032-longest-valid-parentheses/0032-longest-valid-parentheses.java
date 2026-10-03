class Solution {
    public int longestValidParentheses(String s)  {
        int len = 0;
        int answer = 0;
        int n = s.length();
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++)
        {
            char a = s.charAt(i);
            if (a == '(')
            {
                stack.add(-1);
            }
            else if (a == ')')
            {
                while (stack.size() != 0 && stack.lastElement() >= 0)
                {
                    len += stack.lastElement();
                    stack.removeLast();
                }
                if (stack.size() == 0 || stack.lastElement() != -1)
                {
                    len = 0;
                    stack.add(-2);
                }
                else if (stack.lastElement() == -1)
                {
                    stack.removeLast();
                    len += 2;
                    if (stack.size() != 0 && stack.lastElement() > 0)
                    {
                        len += stack.lastElement();
                        stack.removeLast();
                    }
                    answer = Math.max(answer, len);
                    stack.add(len);
                    len = 0;
                }
            }   
            // System.out.println(stack);
        }

        {
            answer = Math.max(answer, len);
        }
        return answer;
    }
}