class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = s.size();
        int m = t.size();
        int j = 0;
        for (int i = 0; i < n && j < m; i++)
        {
            if (t[j] == s[i])
            {
                j++;
            }
        }
        return m - j;
    }
};