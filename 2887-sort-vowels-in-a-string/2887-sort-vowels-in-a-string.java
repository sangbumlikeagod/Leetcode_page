class Solution {
    char[] vowels = {'a', 'e', 'i', 'o', 'u', 'O', 'I', 'A', 'E', 'U'}; 
    public String sortVowels(String s) {
        StringBuffer vowelsB = new StringBuffer();
        StringBuffer consonentsB = new StringBuffer();

        for (char c : s.toCharArray())
        {
            boolean flag = false;
            for (char v : vowels)
            {
                if (v == c)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                vowelsB.append(c);
            }
            else
            {
                consonentsB.append(c);
            }
        }  
        char[] ch = vowelsB.toString().toCharArray();
        Arrays.sort(ch);

        vowelsB = new StringBuffer(String.valueOf(ch));
        // Arrays.sort(ch, (a, b) -> {return a - b;});
        // Arrays.sort(ch, (a, b) -> {
        //     return a - b;
        // });
        String answer = "";

        Integer AIdx = 0;
        Integer BIdx = 0;

        for (char c : s.toCharArray())
        {
            boolean flag = false;
            for (char v : vowels)
            {
                 if (v == c)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                answer += vowelsB.charAt(AIdx++);
            }
            else
            {
                answer += consonentsB.charAt(BIdx++);
            }
        }  
        return answer;
    }
}