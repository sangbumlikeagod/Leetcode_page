class Solution {
    private long MODULO = (long) 1e9 + 7;
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        // 알려줄수있든없든 알고있는 애들
        int[] current = new int[n * 2];
        // 알려줄수있는 애들
        int[] known = new int[n * 2];
        //
        int[] dKnown = new int[n * 2];
        // 까먹은 애들 
        int[] minus = new int[n * 2];
        current[0] = 1;
        dKnown[delay - 1] = 1;
        minus[forget - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            // 알려줄수있는 애는 
            known[i] = (int) (((long) known[i - 1] - (long) minus[i - 1] + (long) dKnown[i - 1]) % MODULO);
            if (known[i] != 0)
            {
                dKnown[i + delay - 1] = known[i];
            }
            minus[i + forget - 1] = known[i];
            current[i] = (int) (( (long) current[i - 1] + (long) known[i] - (long) minus[i - 1]) % MODULO);
        }

        return (int) (((long) current[n - 1] + MODULO) % MODULO) ;
    }
}