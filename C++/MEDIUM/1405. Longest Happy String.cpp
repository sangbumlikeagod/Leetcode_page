class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string answer_pre;
        int last = -1;
        if (a >= b && a >= c)
        {
            answer_pre += 'a';
            a--;
            last = 0;
        }
        else if (b >= c && b >= a)
        {
            answer_pre += 'b';
            b--;
            last = 1;
        }
        else if (c >= a && c >= b)
        {
            answer_pre += 'c';
            c--;
            last = 2;
        }
        if ((a == 0 && b == 0) || (b == 0 && c == 0) || (a == 0 && c == 0))
        {
        }
        else
        {
            while (true)
            {
                // cout << last;
                if (last == 0)
                {
                    if (b > c)
                    {
                        answer_pre += 'b';
                        b--;
                        last = 1;
                        if (a == 0 && c == 0)
                        {
                            break;
                        }
                    }
                    else
                    {
                        answer_pre += 'c';
                        c--;
                        last = 2;
                        if (a == 0 && a == 0)
                        {
                            break;
                        }
                    }
                }
                else if (last == 1)
                {
                    if (a > c)
                    {
                        answer_pre += 'a';
                        a--;
                        last = 0;
                        if (c == 0 && b == 0)
                        {
                            break;
                        }
                    }
                    else
                    {
                        answer_pre += 'c';
                        c--;
                        last = 2;
                        if (b == 0 && a == 0)
                        {
                            break;
                        }
                    }
                }
                else if (last == 2)
                {
                    if (a > b)
                    {
                        answer_pre += 'a';
                        a--;
                        last = 0;
                        if (b == 0 && c == 0)
                        {
                            break;
                        }
                    }
                    else
                    {
                        answer_pre += 'b';
                        b--;
                        last = 1;
                        if (a == 0 && c == 0)
                        {
                            break;
                        }
                    }
                }
            }
        }
        string answer;
        for (char ch : answer_pre)
        {
            answer += ch;
            if (ch == 'a' && a)
            {
                answer += 'a';
                a--;
            }
            else if (ch == 'b' && b)
            {
                answer += 'b';
                b--;
            }
            else if (ch == 'c' && c)
            {
                answer += 'c';
                c--;
            }
        }
        return answer;
    }
};