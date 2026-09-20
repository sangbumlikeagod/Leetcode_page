class Solution {
    long MODULO = (long) (1e9) + 7;
    private int getModuloInverse(int a) {
        // 나누는쪽은 MODULO로 고정 
        int mod = (int) MODULO;
        int r0 = a, r1 = mod;
        int x0 = 1, x1 = 0;
        int y0 = 0, y1 = 1;
        int temp = 0;
        while (r1 != 0)
        {
            int q = r0 / r1;

            temp = r0;
            r0 = r1;
            r1 = temp - q * r0;

            temp = x0;
            x0 = x1;
            x1 = temp - q * x0;

            temp = y0;
            y0 = y1;
            y1 = temp - q * y0;
        }
        return (x0 % mod + mod) % mod;
    }
    long answer = 1;
    public int numberOfSets(int n, int k) {
        
        int xx = Math.min(2 * k, n - 1 - k);

        for (int i = n + k - 1, c = 0; c < xx; i--, c++)
        {
            answer *= i;
            answer %= MODULO;
        }
        for (int j = xx; j >= 2; j--)
        {
            answer *= getModuloInverse(j);
            answer %= MODULO;
        }
        return (int) (answer % MODULO);
    }
}