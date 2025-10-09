class Solution {
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length, m = mana.length;
        long total = 0;
        for (int skil : skill)
        {
            total += skil;
        }
        long answer = 0;
        long[] ready = new long[n + 1];
        for (int i = 0; i < m; i++)
        {
            answer = ready[0];
            for (int j = 1; j <= n; j++)
            {
                int duration = skill[j - 1] * mana[i];
                answer = Math.max(answer, ready[j]);
                answer += duration;
                ready[j] = answer;
            }
            ready[0] = answer - (total * mana[i]);
            
            for (int j = 1; j <= n; j++)
            {
                int duration = skill[j - 1] * mana[i];
                ready[j] = ready[j - 1] + duration;
            }
            // System.out.println(Arrays.toString(ready));
        }
        return answer;
    }
}