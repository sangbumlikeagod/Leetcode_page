class Solution {
    public int scoreOfParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        for (char c : s.toCharArray())
        {
            if (c == '(')
            {
                stack.add(-1);
            }
            else
            {
                int myscore = 0;
                if (stack.lastElement() == -1)
                {
                    stack.removeLast();
                    myscore += 1;
                }
                else
                {
                    myscore += stack.lastElement();
                    stack.removeLast();
                    stack.removeLast();
                    myscore *= 2;
                }

                if (stack.size() != 0 && stack.lastElement() != -1)
                {
                    myscore += stack.lastElement();
                    stack.removeLast();
                }
                stack.add(myscore);
            }
            // System.out.println(stack);
        }
        return stack.lastElement();
    }
}