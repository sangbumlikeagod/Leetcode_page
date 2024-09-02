class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long total = 0;
        for (int i = 0; i < chalk.size(); i++)
        {
            total += chalk[i];
        }
        k %= total;
        int i = 0;
        while (k >= chalk[i])
        {
            k -= chalk[i];
            i = i == chalk.size() - 1 ? 0 : (i + 1);
        }
        return i;
    }
};