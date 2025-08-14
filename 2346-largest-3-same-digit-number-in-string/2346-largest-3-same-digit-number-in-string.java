class Solution {
    public String largestGoodInteger(String num) {
        
        String tmp = "";
        String answer = "";

        for (int i = 0; i < num.length(); i++)
        {
            if (tmp.length() != 0 && tmp.charAt(tmp.length() - 1) == num.charAt(i))
            {
                tmp += num.charAt(i);
            } 
            else
            {
                tmp = String.valueOf(num.charAt(i));
            }
            if (tmp.length() == 3)
            {
                if (answer.length() == 0)
                {
                    answer = tmp;
                }
                else if (answer.charAt(0) < tmp.charAt(0))
                {
                    answer = tmp;
                }   
            }
        }
        return answer;
    }
}