class Solution {
        vector<vector<int>> dp;
        vector<vector<int>> alphabetQ;
        int MODULO = 1000000007;
public:
    int numWays(vector<string>& words, string target) {
        int wordSize = words[0].size();
        int targetLength = target.length();
        dp.resize(2, vector<int> (wordSize, 0));
        alphabetQ.resize(26, vector<int> (wordSize, 0));


        for (int j = 0; j < wordSize; j++)
        {
            for (int i = 0; i < words.size(); i++)
            {
                string& word = words[i];
                alphabetQ[word[j] - 'a'][j]++;
            }
        }
        for (int i = 0; i < wordSize; i++)
        {
            dp[0][i] = alphabetQ[target[0] - 'a'][i];
        }

        int dp_idx = 0;
        int tmp;
        long long next;
        for (int i = 0; i < targetLength - 1; i++)
        {
            for (int j = 0; j < wordSize - 1; j++)
            {
                if (dp[dp_idx][j])
                {
                    tmp = alphabetQ[target[i + 1] - 'a'][j + 1];
                    {
                        dp[dp_idx][j + 1] += dp[dp_idx][j];
                        dp[dp_idx][j + 1] %= MODULO;
                    }

                    if (tmp)
                    {
                        next = (long long) dp[dp_idx][j] * (long long) tmp;
                        dp[!dp_idx][j + 1] += (next % MODULO);
                        dp[!dp_idx][j + 1] %= MODULO;
                    }
                }
            }
            for (int j = 0; j < wordSize; j++)
            {
                dp[dp_idx][j] = 0;
            }
            dp_idx = !dp_idx;
        }

        int answer = 0;
        for (int i = 0; i < wordSize; i++)
        {
            answer += dp[dp_idx][i];
            answer %= MODULO;
        }
        return answer;
    }
};