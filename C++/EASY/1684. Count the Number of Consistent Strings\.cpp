class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        vector<int> alphabet(26, 0);
        for (char c : allowed)
        {
            alphabet[c - 'a']++;
        }

        int answer = 0;
        for (string word : words)
        {
            bool isPass = true;
            for (char c : word)
            {
                if (!alphabet[c - 'a'])
                {
                    isPass = false;
                    continue;
                }
            }
            if (isPass)
                answer++;
        }
        return answer;
    }
};