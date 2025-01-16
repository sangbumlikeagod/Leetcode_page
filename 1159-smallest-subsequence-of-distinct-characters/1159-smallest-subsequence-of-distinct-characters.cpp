class Solution {
public:
    string smallestSubsequence(string s) {
        vector<vector<int>> alphabets(s.length() + 1, vector<int> (26, 0));
        for (int i = 0; i < s.length(); i++)
        {
            alphabets[i][s[i] - 'a']++;
            for (int j = 0; j < 26; j++)
            {
                alphabets[i + 1][j] = alphabets[i][j];
            }
        }  

        vector<int> occupy(26, 0);
        vector<char> answers {s[0]};  
        occupy[s[0] - 'a'] = 1;
        for (int i = 1; i < s.length(); i++)
        {
            char c = s[i];
            if (occupy[c - 'a']) continue;
            while (!answers.empty() && answers.back() > c)
            {
                if (alphabets[s.length()][answers.back() - 'a'] -  \
                alphabets[i][answers.back() - 'a'] == 0)
                {
                    break;
                }
                else
                {
                    occupy[answers.back() - 'a'] = 0;
                    answers.pop_back();
                }
            }
            occupy[c - 'a'] = 1;
            answers.push_back(c);
        }
        string answer;
        for (char c : answers)
        {
            answer += c;
        }
        return answer;
    }
};