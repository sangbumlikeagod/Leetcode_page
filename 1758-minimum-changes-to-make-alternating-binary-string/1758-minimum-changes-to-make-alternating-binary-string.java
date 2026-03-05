class Solution {
    public int minOperations(String s) {
        int answer1 = 0;
        int answer2 = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1)
            {
                if (s.charAt(i) == '1')
                {
                    answer2++;
                }
                else
                {
                    answer1++;
                }
            }
            else
            {
                if (s.charAt(i) == '0')
                {
                    answer2++;
                }
                else
                {
                    answer1++;
                }
            }
        }
        return Math.min(answer1, answer2);
    }
}