class Solution {
    public int maxOperations(String s) {

        boolean consecutive = true;
        int minimum = 0, answer = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s.charAt(i) == '1')
            {
                if (!consecutive)
                {
                    minimum++;
                }
                consecutive = true;
                answer += minimum;
            }
            else
            {
                consecutive = false;
            }
        }
        return answer;
    }
}