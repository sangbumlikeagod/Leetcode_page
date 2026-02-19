class Solution {
    public int countBinarySubstrings(String s) {
        int prev0 = 0;
        int prev1 = 0;
        int current0 = 0;
        int current1 = 0;
        int answer = 0;
        int idx = 0;
        for (char c : s.toCharArray())
        {
            // System.out.println(idx++);
            // System.out.println(prev0 + " " + prev1 + " " + current0 + " " + current1 + " " + answer); 
            if (c == '1')
            {
                if (current1 != 0)
                {
                    current1++;
                    if (current1 <= prev0)
                    {
                        answer++;
                    }
                }
                else
                {
                    

                    prev0 = current0;
                    prev1 = 0;
                    current0 = 0;
                    current1 = 1;
                    if (current1 <= prev0)
                    {
                        answer++;
                    }
                }
            }
            else
            {
                if (current0 != 0)
                {
                    current0++;
                    if (current0 <= prev1)
                    {
                        answer++;
                    }
                }
                else
                {

                    prev1 = current1;
                    prev0 = 0;
                    current1 = 0;
                    current0 = 1;

                    if (current0 <= prev1)
                    {
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
}