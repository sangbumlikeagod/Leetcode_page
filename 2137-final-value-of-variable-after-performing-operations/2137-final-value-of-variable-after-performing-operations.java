class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int answer = 0;
        for (String oper : operations)
        {
            int tmp = 0;
            for (int i = 0; i < 3; i++)
            {
                if (oper.charAt(i) == '+')
                {
                    tmp++;
                }   
            }
            if (tmp >= 2) 
            {
                answer++;
            }
            else
            {
                answer--;
            }
        }
        return answer;
    }
}