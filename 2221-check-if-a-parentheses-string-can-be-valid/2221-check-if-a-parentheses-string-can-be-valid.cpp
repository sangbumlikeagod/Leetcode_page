class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2) return false;
        // if (s[s.length() - 1] == '(' && locked[s.length() - 1] == '1') return false;
        vector<int> args (s.length() + 1, 0);
        vector<int> zeroCounts (s.length() + 1, 0);
        int zeroCount = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (locked[i] == '1')
            {
                if (s[i] == '(')
                {
                    args[i]++;
                }
                else
                {
                    if (args[i] == 0)
                    {
                        if (zeroCount == 0) return false;
                        zeroCount--;
                    }
                    else
                    {
                        args[i]--;
                    }
                }
            }
            else
            {
                zeroCount++;
            }
            args[i + 1] = args[i];
            zeroCounts[i] = zeroCount;
        }

        for (int i = s.length() - 1; i >= 0; i--)
        {
            char a = s[i];
            char b = locked[i];
            if (!args[i]) break;
            if (a == '(' && locked[i] == '1') 
            {   
                if (!(zeroCount - zeroCounts[i])) return false;
                zeroCount--;
            }
            else if (a == ')' && locked[i] == '1')
            {
                zeroCount++;
            }
        }
        return true;
    }
};