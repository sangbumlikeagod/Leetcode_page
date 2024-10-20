class Solution
{

    bool recursion(string &s, int &index, int type)
    {
        bool ret = type == 1 ? true : false;
        while (index < s.length())
        {
            char c = s[index];
            if (c == ',')
            {
                index++;
                continue;
            }
            else if (c == '!')
            {
                index += 2;
                ret = type == 1 ? ret & recursion(s, index, 0) : ret | recursion(s, index, 0);
            }
            else if (c == '&')
            {
                index += 2;
                ret = type == 1 ? ret & recursion(s, index, 1) : ret | recursion(s, index, 1);
            }
            else if (c == '|')
            {
                index += 2;
                ret = type == 1 ? ret & recursion(s, index, 2) : ret | recursion(s, index, 2);
            }
            else if (c == ')')
            {
                index++;
                break;
            }
            else
            {
                ret = type == 1 ? ret & (c == 't') : ret | (c == 't');
                index++;
            }
        }
        return type ? ret : !ret;
    }

public:
    bool parseBoolExpr(string expression)
    {
        int index = 0;
        return recursion(expression, index, 2);
    }
};