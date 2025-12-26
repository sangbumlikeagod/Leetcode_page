class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int[] prefixForward = new int[n + 1];
        int[] prefixBackward = new int[n + 1];

        for (int i = 0; i < n; i++)
        {
            prefixForward[i + 1] = prefixForward[i];
            if (customers.charAt(i) == 'N')
            {
                prefixForward[i + 1]++;
            }
        }
        for (int j = n - 1; j >= 0; j --)
        {
            prefixBackward[j] = prefixBackward[j + 1];
            if (customers.charAt(j) == 'Y')
            {
                prefixBackward[j]++;
            } 
        }

        int answer = 0;
        int answerValue = n;
        for (int i = 0; i <= n; i++)
        {
            if (prefixForward[i] + prefixBackward[i] < answerValue)
            {
                answer = i;
                answerValue = prefixForward[i] + prefixBackward[i];
            }
        }
        return answer;

    }
}