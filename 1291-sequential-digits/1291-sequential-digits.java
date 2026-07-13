class Solution {
    private boolean greaterThan(String s, int top){
        // System.out.println(s + " " + top);
        for (int i = 0; i < s.length(); i++)
        {
            if (s.charAt(i) - '0' < top)
            {
                // System.out.println("TRUE");
                return true;
            }
            else if (s.charAt(i) - '0' > top)
            {
                // System.out.println("FALSE");
                return false;
            }
            top++;
        }
        return true;
    }
    private boolean lessThan(String b, int top){
        // System.out.println(b + " " + top);

        for (int i = 0; i < b.length(); i++)
        {
            if (b.charAt(i) - '0' > top)
            {
                // System.out.println("TRUE");
                return true;
            }
            else if (b.charAt(i) - '0' < top)
            {
                // System.out.println("FALSE");

                return false;
            }
            top++;
        }
        return true;
    }
    private Integer buildAnswer(int top, int digit) {
        int answer = 0;
        for (int i = 0; i < digit; i++)
        {
            answer *= 10;
            answer += top;
            top++;
        }
        return answer;
    }

    public List<Integer> sequentialDigits(int low, int high) {
        String s = String.valueOf(low);
        String b = String.valueOf(high);
        List<Integer> answer = new ArrayList<>();
        int lDigit = s.length();
        int rDigit = b.length();
        
        for (int d = lDigit; d <= rDigit; d++)
        {

            for (int top = 1; top < 10; top++)
            {
                if (top + d > 10) continue;
                if (d == lDigit)
                {
                    if (!greaterThan(s, top))
                    {
                        continue;
                    }
                }
                if (d == rDigit)
                {
                    if (!lessThan(b, top))
                    {
                        continue;
                    }
                }
                answer.add(buildAnswer(top, d));
            }
        }
        return answer;
    }
}