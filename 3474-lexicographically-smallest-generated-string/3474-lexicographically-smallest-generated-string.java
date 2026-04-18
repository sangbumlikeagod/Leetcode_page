class Solution {
    public String generateString(String str1, String str2) {
        int n = str1.length();
        int m = str2.length();

        char[] answer = new char[n + m - 1];
        Arrays.fill(answer, 'a');
        boolean[] isFixed = new boolean[n + m - 1];

        for (int i = 0; i < n; i++)
        {
            if (str1.charAt(i) == 'T')
            {
                for (int j = i; j < i + m; j++)
                {
                    if (isFixed[j] && answer[j] != str2.charAt(j - i))
                    {
                        return "";
                    }
                    answer[j] = str2.charAt(j - i);
                    isFixed[j] = true;
                }
            }

        }

        for (int i = 0; i < n; i++)
        {
            // F인데 
            // 1. 고칠 필요가 없으면 넘어가
            // 2. 고칠 필요가 있으면 가장 나중에있는 놈 인덱스를 바꿔
            // 3. 바꿀만한 lastIndex가 없으면 에러로 리턴
            if (str1.charAt(i) == 'F')
            {
                int lastFreeIndex = -1; 
                boolean needToFix = true;
                for (int j = i; j < i + m; j++)
                {
                    if (answer[j] != str2.charAt(j - i))
                    {
                        needToFix = false;
                        break;
                    }
                    if (isFixed[j] == false)
                    {
                        lastFreeIndex = j;
                    }
                }

                if (needToFix)
                {
                    if (lastFreeIndex == -1) return "";
                    char next = str2.charAt(lastFreeIndex - i) == 'a' ? 'b' : 'a';
                    answer[lastFreeIndex] = next;
                }
            }
        }


        return new StringBuffer().append(answer).toString();
    }
}