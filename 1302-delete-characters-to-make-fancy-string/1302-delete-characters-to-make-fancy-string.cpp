class Solution {
public:
    string makeFancyString(string s) {
        char b2 = ' ';
        char b1 = ' ';
        string answer = "";
        for (char c : s)
            {
                if (b1 == b2)
                {
                    if (c == b1)
                    {
                        continue;
                    }
                }
                answer += c;
                b2 = b1;
                b1 = c;
            }
        return answer;
        
    }
};