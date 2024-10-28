class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int answer = 0;
        vector<int> vec;
        for (char c : s)
        {
            if (c == '(')
            {
                vec.push_back(-1);
            }
            else
            {
                if (vec.empty())
                {
                    vec.push_back(0);
                    continue;
                }
                int cur = 0;
                if (vec.back() == -1)
                {
                    if (vec.size() > 1 && vec[vec.size() - 2] > 0)
                    {
                        vec.pop_back();
                        vec.back()++;
                    }
                    else
                    {
                        vec.pop_back();
                        vec.push_back(1);
                    }
                    answer = max(answer, vec.back());
                }
                else if (vec.back() == 0)
                {
                    vec.push_back(0);
                }
                else
                {
                    if (vec.size() > 1 && vec[vec.size() - 2] == -1)
                    {
                        cur = 1;
                        cur += vec.back();
                        vec.pop_back();
                        vec.pop_back();
                        while (!vec.empty() && vec.back() > 0)
                        {
                            cur += vec.back();
                            vec.pop_back();
                        }
                        vec.push_back(cur);
                        answer = max(answer, vec.back());
                    }
                    else
                    {
                        vec.push_back(0);
                    }
                }
            }
        }
        return answer * 2;
    }
};