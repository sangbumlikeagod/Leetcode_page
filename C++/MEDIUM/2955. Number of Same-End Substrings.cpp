class Solution
{
    vector<vector<int>> prefixSum;

public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>> &queries)
    {
        int ssz = s.length();
        prefixSum = vector<vector<int>>(ssz + 1, vector<int>(26, 0));
        for (int i = 0; i < ssz; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                prefixSum[i + 1][j] = prefixSum[i][j];
            }
            prefixSum[i + 1][s[i] - 'a']++;
        }
        vector<int> answer;
        for (vector<int> query : queries)
        {
            int s = query[0], e = query[1] + 1;
            int partAns = 0;
            for (int i = 0; i < 26; i++)
            {
                int arg = prefixSum[e][i] - prefixSum[s][i];
                partAns += (arg + 1) * arg / 2;
            }
            answer.emplace_back(partAns);
        }
        return answer;
    }
};