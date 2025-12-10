class Solution {
    int MODULO = (int) 1e9 + 7;
    public int countPermutations(int[] complexity) {
        int n = complexity.length;
        long answer = 1;
        for (int i = 1; i < n; i++)
        {
            if (complexity[0] >= complexity[i])
            {
                return 0;
            }
            answer *= i;
            answer %= MODULO;
        }
        return (int) answer;
    }
}