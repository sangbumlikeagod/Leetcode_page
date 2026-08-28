class Solution {
    private boolean greatestFilter(int[] arr)
    {
        int oddCount = 0;
        for (int a : arr)
        {
            oddCount += (a % 2);
        }
        return oddCount <= 1;
    }
    private boolean checkBounded(int[] sArr, String target, char c)
    {
        // greatFilter 지남 
        int n = target.length();
        int check_middle = n % 2;

        // 같아도 되는지를 확인중 
        boolean isBounded = false;
        if (c != '1' && check_middle == 1)
        {
            // 여기서 fasle가 떴을텐데 
            if (c > target.charAt(n / 2))
            {
                return true;
            }
            else if (c < target.charAt(n / 2))
            {
                return false;
            }
        }
        // 중간이 이미 크면 사실 리턴해도됨, 같거나작을경우를 생각해야함 
        // target의 앞의 반을 뒤집은 것이 뒤의 반이 더 큰가
        for (
            int i = n / 2 - 1, j = n / 2 + n % 2; 
            i >= 0;
            i--, j++
        )
        {
            if (target.charAt(i) > target.charAt(j))
            {
                isBounded = true;
                break;
            }
            else if (target.charAt(i) < target.charAt(j))
            {
                isBounded |= false;
                break;
            }
        }
        return isBounded;
    }

    public String lexPalindromicPermutation(String s, String target) {
        int[] sc= new int[26];
        int[] scc= new int[26];

        for (char c : s.toCharArray())
        {
            sc[c - 'a']++;
            scc[c - 'a']++;
        }

        if (!greatestFilter(sc))
        {
            return "";
        }


        char c = '1';
        for (int i = 0; i < 26; i++)
        {
            if (sc[i] % 2 == 1)
            {
                c = (char) ('a' + i);
            }
        }

        
        boolean isBounded = checkBounded(sc, target, c);
        

        for (int i = 0 ; i < 26; i++)
        {
            sc[i] /= 2;
            scc[i] /= 2;
        }
        // 반갈죽이 맞음 여기서 
        int[] tc = new int[26];
        int n = target.length();
        for (int i = 0; i < n / 2; i++)
        {
            tc[target.charAt(i) - 'a']++;
        }
        // System.out.println(Arrays.toString(tc));
        // 더 큰놈을 여기에 채워 넣을 수 있냐? 
        int[] possible = new int[n / 2];
        for (int i = 0; i < n / 2; i++)
        {
            int x = target.charAt(i) - 'a';
            for (int j = x + 1; j < 26; j++)
            {
                if (scc[j] != 0)
                {
                    possible[i] = 1;
                    break;
                }
            }
            if (scc[x] == 0)
            {
                break;
            }
            scc[x]--;
        }

        // System.out.println(s+ " " +  isBounded);
        // System.out.println("possble "+ Arrays.toString(possible));

        StringBuffer answer = new StringBuffer();
        
        // 큰건 나중에 큰것이 더 좋다
        // 그렇기 떄문에 가장 먼저 바꿀 수 있는 애를 확인하려고 했던건데 
        if (isBounded)
        {
            // 아예 처음 값을 재현할 수 있는지만 확인
            int[] tcc = new int[26];
            for (int i = 0; i < n / 2; i++)
            {
                tcc[target.charAt(i) - 'a']++;
            }
            boolean perfectlyFit = true; 
            for (int i = 0; i < 26; i++)
            {
                if (tcc[i] != sc[i])
                {
                    perfectlyFit = false;
                    break;
                }
            }
            if (perfectlyFit)
            {
                
                for (int i = 0; i < n / 2; i++)
                {
                    answer.append(target.charAt(i));
                }
                if (c != '1')
                {
                    answer.append(c);
                }
                for (int i = (n / 2) - 1; i >= 0; i--)
                {
                    answer.append(target.charAt(i));
                }
                return answer.toString();
                // 아예 뒤집은애 리턴 
            }
        }

        // 완전 같을 경우는 없음 
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            if (possible[i] == 0)
            {
                continue;
            }
            // 앞에까진 그대로 반영
            for (int j = 0; j < i; j++)
            {
                char cc = target.charAt(j);
                answer.append(cc);
                sc[cc - 'a']--;
            }
            int x = target.charAt(i) - 'a';
            for (int j = x + 1; j < 26; j++)
            {
                if (sc[j] != 0)
                {
                    sc[j]--;
                    answer.append((char) ('a' + j));
                    break;
                }
            }
            // 여기까진 가장큰놈 더하고 

            for (int j = i + 1; j < n / 2; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    if (sc[k] != 0)
                    {
                        sc[k]--;
                        answer.append((char) ('a' + k));
                        break;
                    }
                }
            }
            break;
        }
        if (answer.length() != (n / 2))
        {
            return "";
        }
        if (
            c != '1' && 
            (answer.length() != 0 || isBounded)
        )
        {
            answer.append(c);
        }
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            answer.append(answer.charAt(i));
        }

        // 여기서부터 반대로 마저 더함, 
        // System.out.println("buffer: " + "  " + answer);
        // System.out.println(Arrays.toString(possible));
        return answer.toString();
    }
}