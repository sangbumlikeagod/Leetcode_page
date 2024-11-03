class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        vector<vector<int>> qp(26, vector<int>{});
        for (int i = 0; i < s.length(); i++)
        {
            qp[goal[i] - 'a'].push_back(i);
        }

        for (int j : qp[s[0] - 'a'])
        {
            bool isAnswer = true;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] != goal[j])
                {
                    isAnswer = false;
                    break;
                }
                j += 1;
                j %= goal.length();
            }
            if (isAnswer)
                return true;
        }
        return false;
    }
};