class Solution {
public:
    int takeCharacters(string s, int k) {
        if (!k)
        {
            return 0;
        }
        vector<vector<int>> SS(3, vector<int>(s.length() + 1, 0));
        int answer = s.length() + 1;
        for (int i = 1; i <= s.length(); i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int prev = i == 0 ? 0 : SS[j][i - 1];
                if (s[i - 1] - 'a' == j)
                {
                    SS[j][i] = prev + 1;
                }
                else
                {
                    SS[j][i] = prev;
                }
            }
        }
        vector<vector<int>> BB(3, vector<int>(s.length() + 1,0));
        for (int i = s.length(); i > 0; i--)
        {
            for(int j = 0; j < 3; j++)
            {
                int prev = i == s.length()? 0 : BB[j][s.length() - i];
                if (s[i - 1] - 'a' == j)
                {
                    BB[j][s.length() - i + 1] = prev + 1;
                }
                else
                {
                    BB[j][s.length() - i + 1] = prev;
                }
            }
        }
        for (int i = 0; i <= s.length(); i++)
        {
            int maX = 0;
            for (int j = 0; j < 3; j++)
            {
                int remain = k - SS[j][i] - 1;
                // cout << remain << '\n';
                int idx = upper_bound(BB[j].begin(), BB[j].end(), remain) - BB[j].begin();
                maX = max(maX, idx);
            }
            // cout << maX << ' ' <<  i << '\n';
            answer = min(answer, maX + i);
        }

        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j <= s.length(); j++)
        //     {
        //         cout << SS[i][j] << ':' << BB[i][j] << '\t';
        //     }
        //     cout << '\n';
        // }
        // cout << 'A';
        return answer == s.length() + 1 ? - 1: answer;
    }
};