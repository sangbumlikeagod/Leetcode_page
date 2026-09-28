class Solution {
    public int maxDepth(String s) {
        int answer = 0;
        int cr = 0;
        for (char c : s.toCharArray())
        {
            if (c == '(')
            {
                cr += 1;
            }
            else if (c == ')')
            {
                cr -= 1;
            }
            answer = Math.max(answer, cr);
        }
        return answer;
    }
}