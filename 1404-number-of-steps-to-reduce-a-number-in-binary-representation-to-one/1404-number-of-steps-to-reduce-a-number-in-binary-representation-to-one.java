class Solution {
    public int numSteps(String s) {
        int n = s.length() - 1;
        int consecutive = 1;
        int answer = 0;
        char lastCharacter = s.charAt(n);
        for (;n >= 0 ;n--)
        {
            if (n != s.length() - 1)
            {
                if (s.charAt(n) == lastCharacter)
                {
                    consecutive++;
                }
                else
                {
                    answer += s.charAt(n) == '1' ? consecutive : consecutive + 1;
                    consecutive = 1;
                    lastCharacter = '1';
                }
            }
        }
        if (consecutive > 1)
        {
            answer += s.charAt(0) == '1' ? consecutive + 1: consecutive;
        }
        return answer;
    }
}