class Solution {
public:
    string reversePrefix(string word, char ch) {
        string prefix;
        bool isPrefix = true;
        for (int a = 0; a < word.length(); a++)
        {
            if (word[a] == ch && isPrefix)
            {
                isPrefix = false;
                prefix += word[a];
                reverse(prefix.begin(), prefix.end());
            }
            else
            {
                prefix += word[a];
            }
        }
        return prefix;
    }
};