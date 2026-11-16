class Solution {
    public String digitSum(String s, int k) {

        while (s.length() > k)
        {

            StringBuffer sb = new StringBuffer();

            for (int i = 0; i < s.length(); i += k)
            {
                int sSum = 0;
                for (int j = i; j < Math.min(i + k, s.length()); j++)
                {
                    sSum += s.charAt(j) - '0';
                }
                sb.append(String.valueOf(sSum));
            }
            s = sb.toString();
        }
        return s;
    }
}