class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0, cheat = 0;
        for (int i = 0; i < s.length(); i++)
        {
            cout << l << ' ' << cheat << ' ' << r << '\n';
            if (s[i] == '(')
            {
                l++;
            }
            else if (s[i] == '*')
            {
                cheat++;
            }
            else
            {
                if (l) 
                {
                    l--;
                }
                else if (cheat)
                {
                    cheat--;
                }
                else
                {
                    return false;
                }
            }
        }
        l = 0; cheat = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                l++;
            }
            else if (s[i] == '*')
            {
                if (l)
                {
                    l--;
                }
            }
            else
            {
                if (l)
                {
                    l--;
                }
            }
        }
        // cout << l << ' ' << cheat << ' ' << r << '\n';
        return l == 0;
    }
};