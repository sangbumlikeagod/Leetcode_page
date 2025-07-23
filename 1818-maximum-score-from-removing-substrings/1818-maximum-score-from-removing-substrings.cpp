class Solution {

private: 
    int maxLocalGain(string& s, int st, int en, int x, int y)
    {
        // cout << st << ' ' << en << '\n';
        int a = 0, b = 0;
        char imp = x > y ? 'b' : 'a';
        int impCount = 0;
        vector<char> stack {};
        for (int i = st; i <= en; i++)
        {

            if (s[i] == imp)
            {
                if (stack.empty() == false && stack.back() != imp)
                {
                    stack.pop_back();
                    impCount++;
                } 
                else
                {
                    stack.push_back(s[i]);
                }
            }
            else
            {
                stack.push_back(s[i]);
            }

            if (s[i] == 'a')
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        int n = min(a, b);
        return (n - impCount) * min(x, y) + (impCount * max(x, y));
    }
public:
    int maximumGain(string s, int x, int y) {
        s += 'c';
        int n = s.length();
        int answer = 0;
        int st = -1, en = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'b')
            {
                if (st == -1)
                {
                    st = i;
                }
                en = i;
            }
            else
            {
                if (st != -1)
                {
                    answer += maxLocalGain(s, st, en, x, y);
                }
                st = -1;
                en = -1;
            }
        }
        return answer;
    }
};