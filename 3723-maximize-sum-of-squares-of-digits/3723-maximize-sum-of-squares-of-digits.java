class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum > num * 9)
        {
            return "";
        }
        int answer = 0;
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < num; i++)
        {
            if (sum >= 9)
            {
                sb.append('9');
                sum -= 9;
            }
            else if (sum > 0)
            {
                sb.append((char) ('0' + sum));
                sum = 0;
            }
            else
            {
                sb.append('0');
            }
        }
        return sb.toString();
    }
}