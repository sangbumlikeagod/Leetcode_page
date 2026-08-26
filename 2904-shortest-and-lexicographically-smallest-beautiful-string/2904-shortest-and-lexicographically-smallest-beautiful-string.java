class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int n = s.length();
        int[] prefixSum = new int[n + 1];
        int[] firstHappen = new int[n + 1];

        Arrays.fill(firstHappen, Integer.MAX_VALUE);

        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = (s.charAt(i) == '1' ?  1 : 0) + prefixSum[i];
            // 여기를 빼버리면 된다는 뜻에서 출발하려고함
            firstHappen[prefixSum[i + 1]] = Math.min(firstHappen[prefixSum[i + 1]], i);   
        }
        if (prefixSum[n] < k)
        {
            return "";
        }
        if (k == 1)
        {
            return "1";
        }
        int len = Integer.MAX_VALUE;
        String answer = null;
        for (int i = k; i <= n; i++)
        {

            if (firstHappen[i] == Integer.MAX_VALUE)  {
                continue;
            }
            if (
                firstHappen[i] - firstHappen[i - k + 1] + 1 < len
            )
            {
                len = Math.min(len, firstHappen[i] - firstHappen[i - k + 1] + 1);
                answer = s.substring(firstHappen[i - k + 1], firstHappen[i] + 1);
            }
            else if (firstHappen[i] - firstHappen[i - k + 1] + 1 == len)
            {
                String sub = s.substring(firstHappen[i - k + 1], firstHappen[i] + 1);
                for (int j = 0; j < len; j++)
                {

                    if (
                        answer == null || (
                        answer.charAt(j) == '1' &&
                        sub.charAt(j) == '0'
                        )
                    )
                    {
                        answer = sub;
                        break;
                    }
                    else if (
                        answer.charAt(j) == '0' &&
                        sub.charAt(j) == '1'
                    )
                    {
                        break;
                    }
                }
            }
        }
        
        return answer;

        


    }
}