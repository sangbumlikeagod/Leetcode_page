class Solution {
    public int[] getNoZeroIntegers(int n) {
        int a = 0, b = 0;
        for (int i = 1; i < n; i++)
        {
            boolean f1 = true,  f2 = true;
            int ic = i, iC = n -i;
            while (ic > 0)
            {
                if (ic % 10 == 0)
                {
                    f1 =false;
                    break;
                }
                ic /= 10;
            }
            if (!f1) continue;
            while (iC > 0)
            {
                if (iC % 10 == 0)
                {
                    f2 = false;
                    break;
                }
                iC /= 10;
            }
            if (!f2) continue;
            return new int[] {i, n - i};
        }
        return new int[] {1, n - 1};
    }
}