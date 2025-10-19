class Solution {
    Integer findGCD(int a, int b)
    {
        while (true)
        {
            if (b > a)
            {
                int tmp = a;
                a = b;
                b = tmp;
            }
            a %= b;
            if (a == 0) break;
        }
        return b;
    }
    public String findLexSmallestString(String s, int a, int b) {
        int n = s.length();
        int[] gce = {0, 10, 10, 10, 5, 2, 5, 10, 5, 10};

        int[] sArray = new int[n];
        for (int i = 0; i < n; i++)
        {
            char c = s.charAt(i);
            sArray[i] = c - '0';
        }

        TreeSet<String> sets = new TreeSet<>();
        // 최대 10번 한칸씩 이동
        for (int k = 0; k <= b * n / findGCD(b, n); k += b)
        {
            // 가능한 인덱스부터 시작해서
            int startIdx = k % n;
            // System.out.println("시작 점은: " + startIdx + " " + b * n / findGCD(b, n));
            // 경우에 따라 그 인덱스에 A를 더한다
            // 최대.. 1000번 미만이겠지 
            for (int i = 0; i < gce[a]; i++)
            {
                // 
                for (int j = 1; j < n; j += 2)
                {
                    // 가능한만큼 데이터를 바꾼다 
                    int idx = (startIdx + j) % n;
                    sArray[idx] = (sArray[idx] + a) % 10; 
                }

                // 모든 조합에 대한 문자를 구함
                if (b % 2 == 1)
                {
                    for (int p = 0; p < gce[a]; p++)
                    {
                        // 
                        for (int j = 0; j < n; j += 2)
                        {
                            // 가능한만큼 데이터를 바꾼다 
                            int idx = (startIdx + j) % n;
                            sArray[idx] = (sArray[idx] + a) % 10; 
                        }
                        StringBuffer args = new StringBuffer();
                        for (int q = 0; q < n; q++)
                        {
                            int idx = (startIdx + q) % n;
                            Integer arg = sArray[idx];
                            args.append(String.valueOf(arg));
                        } 
                        sets.add(args.toString());
                    }

                }
                else
                {
                    StringBuffer args = new StringBuffer();
                    for (int p = 0; p < n; p++)
                    {
                        int idx = (startIdx + p) % n;
                        Integer arg = sArray[idx];
                        args.append(String.valueOf(arg));
                    } 
                    sets.add(args.toString());
                }


                // if (b % 2 == 1)
                // {
                //     for (int j = 0; j < n; j += 2)
                //     {
                //         // 가능한만큼 데이터를 바꾼다 
                //         int idx = (startIdx + j) % n;
                //         sArray[idx] = (sArray[idx] + a) % 10; 
                //     }
                //     // StringBuffer oddArgs = new StringBuffer();
                //     // for (int p = 0; p < n; p++)
                //     // {
                //     //     int idx = (startIdx + p) % n;
                //     //     Integer arg = sArray[idx];
                //     //     oddArgs.append(String.valueOf(arg));
                //     // } 
                //     // sets.add(oddArgs.toString());
                // }
            }
        }
        // System.out.println(sets);
        return sets.first();
        
    }
}