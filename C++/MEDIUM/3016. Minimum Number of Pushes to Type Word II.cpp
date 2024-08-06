class Solution
{
public:
    int minimumPushes(string word)
    {
        int counting[26] = {0};
        char alphabet[26] = {};
        for (int i = 0; i < 26; i++)
        {
            alphabet[i] = 'a' + i;
        }
        for (char c : word)
        {
            counting[c - 'a']++;
        }
        sort(alphabet, alphabet + 26 * sizeof(char), [counting](char a, char b)
             { return counting[a - 'a'] > counting[b - 'a']; });
        int numCount = 0;
        int plus = 1;
        int answer = 0;
        for (int i = 0; i < 26; i++)
        {
            answer += plus * counting[alphabet[i] - 'a'];
            numCount++;
            if (numCount == 8)
            {
                numCount = 0;
                plus++;
            }
        }
        return answer;
    }
};