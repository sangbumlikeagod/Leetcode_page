class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> stdmap;
        vector<string> answer;
        s1 += ' ';
        s2 += ' ';
        string buffer = "";
        for (char c : s1)
        {
            if (c == ' ')
            {
                if (stdmap.find(buffer) == stdmap.end())
                {
                    stdmap[buffer] = 1;
                }
                else
                {
                    stdmap[buffer] = -1;
                }
                buffer.clear();
            }
            else
            {   
                buffer += c;
            }
        }

        for (char c : s2)
        {
            if (c == ' ')
            {
                if (stdmap.find(buffer) == stdmap.end())
                {
                    stdmap[buffer] = 1;
                }
                else
                {
                    stdmap[buffer] = -1;
                }
                buffer.clear();
            }
            else
            {   
                buffer += c;
            }
        }
        auto a = stdmap.begin();
        while (a != stdmap.end())
        {
            if (a -> second != -1)
            {
                answer.push_back(a -> first);
            }
            a++;
        }
        return answer;
    }
};