class Solution {
public:
    string clearDigits(string s) {
        vector<pair<char, int>> doStack {};
        vector<pair<char, int>> nonDoStack {};

        for (int i = 0; i < s.length(); i++){
            char c = s[i];
            if ('0' <= c && c <= '9')
            {
                if (doStack.empty() == false)
                {
                    doStack.pop_back();
                }
                else
                {
                    nonDoStack.push_back({c, i});
                }
            }
            else
            {
                doStack.push_back({c, i});
            }
        }

        int i = 0, j = 0;
        string answer;

        while (i + j < doStack.size() + nonDoStack.size())
        {
            if (i >= doStack.size())
            {
                answer += nonDoStack[j++].first;
            }
            else if (j >= nonDoStack.size())
            {
                answer += doStack[i++].first;
            }
        }
        return answer;
    }
};