class Solution {
public:
    int differenceOfSums(int n, int m) {
        int r1 = 0, r2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % m)
            {
                r1 += i;
            }
            else
            {
                r2 += i;
            }
        }
        return r1 - r2;
    }
};