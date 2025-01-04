class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<int, int> uniqueDef;
        vector<vector<int>> prefixSum(s.length() + 1, vector<int> (26, 0));
        vector<int> lastIndex(26, -1);

        int answer = 0;
        prefixSum[0][s[0] - 'a']++;
        lastIndex[s[0] - 'a'] = 0;
        for (int i = 1; i < s.length(); i++)
        {

            int myIndex = s[i] - 'a';
            for (int j = 0; j < 26; j++)
            {
                prefixSum[i][j] = prefixSum[i - 1][j];
            }
            if (prefixSum[i][myIndex])
            {
                int prevIIndex = lastIndex[myIndex];
                if (prevIIndex >= 0 && prevIIndex != i - 1)
                {
                    for (int k = 0; k < 26; k++)
                    {
                        if (prefixSum[prevIIndex][k] == prefixSum[i][k]) continue;
                        int id = 676 * myIndex + 26 * k + myIndex;
                        if (uniqueDef.find(id) != uniqueDef.end()) continue;
                        uniqueDef[id] = 1;
                        answer++;
                    }
                }
            }
            else
            {
                lastIndex[myIndex] = i;
            }


            prefixSum[i][myIndex]++;

        }
        return answer;
    }
};