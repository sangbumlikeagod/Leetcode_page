class Solution {
    public int longestBalanced(String s) {
        int n = s.length();
        int[][] prefixSum = new int[n + 1][26];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                prefixSum[i + 1][j] = prefixSum[i][j];
            }
            prefixSum[i + 1][s.charAt(i) - 'a']++; 
        }
        int answer = n;
        for (;answer > 0; answer--)
        {
            for (int k = 0; k <= n - answer; k++)
            {   
                int arg = Integer.MAX_VALUE;
                boolean isCorrect = true;
                for (int al = 0; al < 26; al++)
                {
                    int cnt = prefixSum[k + answer][al] - prefixSum[k][al];
                    if (cnt == 0) continue;
                    if (arg == Integer.MAX_VALUE)
                    {
                        arg = cnt;
                    }
                    if (arg != cnt)
                    {
                        isCorrect = false;
                        break;
                    }
                }
                if (isCorrect)
                {
                    return answer;
                }
                else
                {
                    continue;
                }
            }
        }
        return answer;
    }
}