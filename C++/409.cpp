class Solution
{
    int uppercase[26]{0};
    int lowercase[26]{0};

public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        int size = s.length();
        for (char c : s)
        {
            if (c >= 97)
            {
                lowercase[c - 'a']++;
            }
            else
            {
                uppercase[c - 'A']++;
            }
        }

        int isOneMore = 0;
        for (int i = 0; i < 26; i++)
        {
            isOneMore = max(isOneMore, uppercase[i] % 2);
            isOneMore = max(isOneMore, lowercase[i] % 2);
            ans += uppercase[i] - uppercase[i] % 2;
            ans += lowercase[i] - lowercase[i] % 2;
        }
        return ans + isOneMore;
    }
};