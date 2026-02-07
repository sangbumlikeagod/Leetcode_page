class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int[] aLeft = new int[n];
        int[] bRight = new int[n];
        for (int i = 0; i < n; i++)
        {
            aLeft[i] = i == 0 ? 0 : aLeft[i - 1]; 
            if (s.charAt(i) == 'b')
            {
                aLeft[i]++;
            }
        }
        int answer = aLeft[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            bRight[i] = i == n - 1 ? 0 : bRight[i + 1]; 
            if (s.charAt(i) == 'a')
            {
                bRight[i]++;
            }
            if (i != n - 1) answer = Math.min(aLeft[i] + bRight[i + 1], answer);
            if (i != 0) answer = Math.min(answer, aLeft[i - 1] + bRight[i]);
        }
        answer = Math.min(answer, bRight[0]);
        return answer;
    }
}