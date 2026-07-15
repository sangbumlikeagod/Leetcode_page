class Solution {
    private Integer findGCD(int a, int b)
    {   
        if (a < b)
        {
            int tmp = a;
            a = b; b = tmp;
        }
        while (a != 1 && b != 1 && a % b != 0)
        {
            if (a < b)
            {
                int tmp = a;
                a = b; b = tmp;
            }
            a = a % b;
        }
        return b;
    }
    public int gcdOfOddEvenSums(int n) {
        int ev = (n * n) + n;
        int od = n * n;
        return findGCD(od, ev);
    }
}