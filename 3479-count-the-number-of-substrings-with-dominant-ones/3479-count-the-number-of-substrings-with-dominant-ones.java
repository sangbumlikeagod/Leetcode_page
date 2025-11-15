class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int[] lastZeros = new int[n + 1];
        lastZeros[0] = -1;

        // for (int i = 0; i < n; i++)
        // {
        //     int isZero = s.charAt(i) == '0' ? 1 : 0;

        //     if (isZero == 1)
        //     {
        //         lastZeros[i + 1] = i;
        //     }
        //     else
        //     {
        //         lastZeros[i + 1] = lastZeros[i];
        //     }
        // }

        for (int i = 0; i < n; i++) {
            // 이전 인덱스가 0보
            if (i == 0 || (i > 0 && s.charAt(i - 1) == '0')) {
                lastZeros[i + 1] = i;
            } else {
                lastZeros[i + 1] = lastZeros[i];
            }
        }


        int answer = 0;

        for (int r = 1; r <= n; r++)
        {
            int cnt0 = s.charAt(r - 1) == '0' ? 1 : 0;
            int l = r;

            while (l > 0 && cnt0 * cnt0 <= n)
            {
                int cnt1 = (r - lastZeros[l]) - cnt0;
                if (cnt0 * cnt0 <= cnt1)
                {
                    answer += Math.min(l - lastZeros[l], cnt1 - cnt0 * cnt0 + 1);
                }
                l = lastZeros[l];
                cnt0++;
            }
        }
        
        
        return answer;
    }
}