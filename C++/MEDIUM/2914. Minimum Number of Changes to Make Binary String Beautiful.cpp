
class Solution
{
public:
    int minChanges(string s)
    {
        int answer = 0;
        for (int idx = 0; idx < s.length(); idx += 2)
        {
            if (s[idx] != s[idx + 1])
                answer++;
        }
        return answer;
    }
};