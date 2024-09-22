class Solution
{

private:
    int getNum(long long a, long long b, int &n)
    {
        int tmp = 0;
        while (a <= n)
        {
            tmp += min(n + 1, (int)b) - a;
            a *= 10;
            b *= 10;
        }
        return tmp;
    }

public:
    int findKthNumber(int n, int k)
    {
        long long num = 1;
        for (int i = 1; i < k;)
        {
            int tm = getNum(num, num + 1, n);
            if (i + tm <= k)
            {
                i += tm;
                num++;
            }
            else
            {
                i++;
                num *= 10;
            }
        }
        return (int)num;
    }
};