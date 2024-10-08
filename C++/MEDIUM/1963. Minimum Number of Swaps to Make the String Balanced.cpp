class Solution
{
public:
    int minSwaps(string s)
    {
        int l = 0, r = 0;
        for (char c : s)
        {
            if (c == '[')
            {
                l++;
            }
            else
            {
                if (l)
                {
                    l--;
                }
            }
        }
        return l / 2 + l % 2;
    }
};