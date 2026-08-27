class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int[] charss = new int[26];
        int[] charsss = new int[26];
        int[] chartt = new int[26];
        int[] charttt = new int[26];
        int n = s.length();
        StringBuffer answer = new StringBuffer();
        if (n == 1)
        {
            return s.charAt(0) > target.charAt(0) ? s : "";
        }

        for (int i = 0; i < n; i++)
        {
            charss[s.charAt(i) - 'a']++;
            charsss[s.charAt(i) - 'a']++;
            chartt[target.charAt(i) - 'a']++;
            charttt[target.charAt(i) - 'a']++;
        }
        // 마지막은 뺴야함
        
        int[] possible = new int[n];
        for (int i = 0; i < n; i++)
        {
            int x = target.charAt(i) - 'a';
            for (int j = x + 1; j < 26; j++)
            {
                if (charss[j] != 0)
                {
                    possible[i] = 1;
                    break;
                }
            }
            if (charss[x] == 0)
            {
                break;
            }
            charss[x]--;
        }
        // 그리디 접근이 아예안되나
        for (int i = n - 1; i >= 0; i--)
        {
            if (possible[i] == 0)
            {
                continue;
            }
            System.out.println(i);
            // 여기에 오면 최소라는게 확정된상황
            for (int j = 0; j < i; j++)
            {
                char c = target.charAt(j);
                answer.append(c);
                charsss[c - 'a']--;
            }
            int x = target.charAt(i) - 'a';
            for (int j = x + 1; j < 26; j++)
            {
                if (charsss[j] != 0)
                {
                    charsss[j]--;
                    answer.append((char) ('a' + j));
                    break;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    if (charsss[k] != 0)
                    {
                        charsss[k]--;
                        answer.append((char) ('a' + k));
                        break;
                    }
                }
            }
            break;
        }

    
        return answer.toString();
    }
}