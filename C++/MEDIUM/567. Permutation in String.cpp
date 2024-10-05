class Solution
{
    vector<int> original;
    vector<int> slidingWindow;

private:
    bool checkSame()
    {
        for (int i = 0; i < 26; i++)
        {
            if (original[i] != slidingWindow[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        original = vector<int>(26, 0);
        slidingWindow = vector<int>(26, 0);
        int s1L = s1.length();
        int s2L = s2.length();
        if (s2L < s1L)
        {
            return false;
        }
        for (char c : s1)
        {
            original[c - 'a']++;
        }
        for (int i = 0; i < s1L; i++)
        {
            slidingWindow[s2[i] - 'a']++;
        }
        int s = 0, e = s1L;
        if (checkSame())
            return true;
        while (e < s2L)
        {
            slidingWindow[s2[s] - 'a']--;
            s++;
            slidingWindow[s2[e] - 'a']++;
            e++;
            if (checkSame())
            {
                return true;
            }
        }
        return false;
    }
};