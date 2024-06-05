class Solution
{
    vector<vector<int>> wordsAlphabet = vector<vector<int>>(101, vector<int>(26, 0));

public:
    vector<string> commonChars(vector<string> &words)
    {
        for (int index = 0; index < words.size(); index++)
        {
            for (char c : words[index])
            {
                wordsAlphabet[index][c - 'a']++;
            }
        }
        vector<string> ans;
        for (int alphabet = 0; alphabet < 26; alphabet++)
        {
            string args = "";
            args += 'a' + alphabet;
            int arg = 100;
            for (int index = 0; index < words.size(); index++)
            {
                arg = min(wordsAlphabet[index][alphabet], arg);
            }
            for (int index = 0; index < arg; index++)
            {
                ans.push_back(args);
            }
        }
        return ans;
    }
};