class Solution {
    int MODULO = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<vector<int>>> dp (26, vector<vector<int>> (31, vector<int>(26, 0)));
         for (int i = 0; i < 26; i++)
         {
            for (int j = 1; j <= nums[i] ; j++)
            {
                dp[i][0][(i + j) % 26] = 1;
            }
         }

        for (int num = 1; num < 31; num++)
        {
            // 내 a부터 z까지 
            for (int x = 0; x < 26; x++)
            {
                // 내 반쪽의 a 부터 z까지  내 인수의 a부터 z까지 
                for (int y = 0; y < 26; y++)
                {
                    if (dp[x][num - 1][y] == 0) continue;
                    for (int z = 0; z < 26; z++)
                    {
                        dp[x][num][z] += ((long long) dp[y][num - 1][z] * dp[x][num - 1][y]) % MODULO;
                        dp[x][num][z]  %= MODULO;
                    }
                }
            }
        }

        vector<int> t_adic(31, 0);
        int _t = 0;
        int last_tt = 0;
        while (t > 0)
        {
            t_adic[_t++] = t % 2;
            t /=2;
        }
        last_tt = _t - 1;

        vector<int> lastDP(26, 0);
        int start = 0;
        int answer = 0;
        for (char c : s)
        {
            if (lastDP[c - 'a'] )
            {
                answer += lastDP[c - 'a'];
                answer %= MODULO;
                continue;
            }
            vector<int> t_digits (26, 0);
            vector<int> t_digits2 (26, 0);
            for (int i = 0; i < 26; i++)
            {
                t_digits[i] = dp[c - 'a'][last_tt][i];
            }


            for (int i = last_tt - 1; i >= 0; i--)
            {
                if (t_adic[i])
                {
                    for (int j = 0; j < 26; j++)
                    {
                        for (int k = 0; k < 26; k++)
                        {
                            t_digits2[k] += ((long long) dp[j][i][k] * t_digits[j]) % MODULO;
                            t_digits2[k] %= MODULO;
                        }
                    }
                }
                else
                {
                    for (int j = 0; j < 26; j++)
                    {
                        t_digits2[j] = t_digits[j];
                        t_digits2[j] %= MODULO;
                    }
                }
                swap(t_digits, t_digits2);
                t_digits2 = vector<int>(26);
            }
            for (int i = 0; i < 26; i++)
            {
                answer += t_digits[i];
                lastDP[c - 'a'] += t_digits[i];
                lastDP[c - 'a'] %= MODULO;
                answer %= MODULO;
            }
        }
        return answer;
    }
};