class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int isDecreasing = time / (n - 1) % 2;
        if (isDecreasing)
        {
            return (n - (time % (n - 1)));
        }
        return 1 + (time % (n - 1));
    }
};