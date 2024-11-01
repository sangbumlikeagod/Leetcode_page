class Solution
{
public:
    string makeFancyString(string s)
    {
        char a = ' ';
        char b = ' ';
        string answer;
        for (char c : s)
        {
            if (a == b && b == c)
                continue;

            answer += c;
            a = b;
            b = c;
        }
        return answer;
    }
};