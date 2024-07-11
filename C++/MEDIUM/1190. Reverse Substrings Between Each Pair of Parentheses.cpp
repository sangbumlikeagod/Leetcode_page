class Solution
{

    void checkString(int &index, bool haveToReverse, string &s)
    {
        int startIndex = index;
        while (index < s.length() && s[index] != ')')
        {
            if (s[index] == '(')
            {
                index++;
                checkString(index, !haveToReverse, s);
            }
            else
            {
                index++;
            }
        }
        if (index < s.length())
        {
            reverse(&s[startIndex], &s[index]);
        }
        index++;
        return;
    }

public:
    string reverseParentheses(string s)
    {
        string answer;
        int index = 0;
        checkString(index, 0, s);
        for (char c : s)
        {
            if (c != '(' && c != ')')
            {
                answer += c;
            }
        }
        return answer;
    }
};