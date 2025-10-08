class Solution {
    private int bs(long[] arrays, long target)
    {
        int l = 0, r = arrays.length;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (arrays[m] >= target)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        // System.out.println(l+ " " + target);
        return l;
    }
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length, m = potions.length;
        
        long[] longPotions = new long[m];
        for (int i = 0; i < m; i++)
        {
            longPotions[i] = (long) potions[i];
        }
        // System.out.println(Arrays.toString(longPotions));
        Arrays.sort(longPotions);
        int[] answer = new int[n];
        for (int i = 0; i < n; i++)
        {
            long target = (success % (long) spells[i]) == 0 ? (success / (long) spells[i])  : (success / (long) spells[i]) + 1;
            answer[i] =  m - bs(longPotions, target);
        }
        return answer;
    }
}