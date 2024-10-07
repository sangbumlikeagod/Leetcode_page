class Solution
{
public:
    int minLength(string s)
    {
        int answer = s.length();
        if (answer == 1)
            return answer;
        vector<char> pos;
        for (char c : s)
        {
            if (!pos.empty() && ((c == 'B' && pos.back() == 'A') || (c == 'D' && pos.back() == 'C')))
            {
                answer -= 2;
                pos.pop_back();
            }
            else
            {
                pos.push_back(c);
            }
        }
        return answer;
    }
};