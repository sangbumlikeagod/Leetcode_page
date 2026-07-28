class Solution {
    private List<Integer> findPattern(String s, String pattern) {
        List<Integer> answer = new ArrayList<>();
        
        int pl = pattern.length();
        int sl = s.length();
        // 초기화 
        int[] xx = new int[pl];
        int[] lasts = new int[26];
        Arrays.fill(xx, -1);
        Arrays.fill(lasts, -1);
        
        for (int i = 0; i < pl; i++)
        {
            xx[i] = lasts[pattern.charAt(i) - 'a'];
            lasts[pattern.charAt(i) - 'a'] = i;
        }
        // System.out.println(Arrays.toString(xx));
        int head = 0;
        while (head + pl - 1 < sl)
        {
            boolean found = true;
            // System.out.println(head);
            for (int k = 0; k < pl; k++)
            {
                if (pattern.charAt(k) != s.charAt(head + k))
                {
                    if (k == 0)
                    {
                        head++;
                    }
                    else
                    {
                        head += k - xx[k - 1] - 1;
                    }
                    found = false;
                    break;
                }
            }
            if (found)
            {
                answer.add(head);
                head++;
            }
            // 도달 
        }
        return answer;

    }
    public String boldWords(String[] words, String s) {

        int[] answers = new int[s.length()];
        for (String word : words)
        {
            if (word.length() > s.length())
            {
                continue;
            }
            List<Integer> patternFound = findPattern(s, word);
            // System.out.println(word + " " + patternFound);
            for (int pattern : patternFound)
            {
                for (int i = 0; i < word.length(); i++)
                {
                    answers[pattern + i] = 1;
                }
            }
        }

        StringBuffer sb = new StringBuffer();
        boolean isBolding = false;
        for (int i = 0; i < s.length(); i++)
        {

            if (answers[i] == 1 && !isBolding)
            {
                sb.append(new char[] {'<', 'b', '>'});
                isBolding = true;
            }
            else if (answers[i] != 1 && isBolding)
            {
                sb.append(new char[] {'<', '/', 'b', '>'});
                isBolding = false;
            }
            sb.append(s.charAt(i));
        }
        if (isBolding)
        {
            sb.append(new char[] {'<', '/', 'b', '>'});   
        }
        return sb.toString();
    }
}