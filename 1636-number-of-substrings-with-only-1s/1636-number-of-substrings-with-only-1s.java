class Solution {
    private long MODULO = (long) 1e9 + 7;
    public int numSub(String s) {
        
        int consecutive = 0;
        int answer = 0;
        int n = s.length();
       for (int i = 0; i <= n; i++)
       {
            if (i != n && s.charAt(i) == '1')
            {
                consecutive++;
            }
            else
            {
                if (consecutive != 0)
                {
                    // nH2 
                    answer += (int) (((long) (consecutive + 1) * consecutive / 2) % MODULO);
                }
                consecutive = 0;
            }
       } 
       return answer;
    }
}