class Solution
{
    typedef long long ll;
    unordered_map<int, int> container;

public:
    bool judgeSquareSum(int c)
    {
        ll limit = (long long)(1 << 31) - 1;
        ll start = 0;
        while (start * start <= c)
        {
            container[(int)start * start] = 1;
            start++;
        }
        for (unordered_map<int, int>::iterator ac = container.begin(); ac != container.end(); ac++)
        {
            if (container.find(c - ac->first) != container.end())
            {
                return true;
            }
        }
        return false;
    }
};