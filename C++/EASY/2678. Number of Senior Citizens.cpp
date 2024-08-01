class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int answer = 0;
        for (string s : details)
        {
            int isSixty;
            if (s[11] - '0' >= 6)
            {
                isSixty = (s[11] == '6') && (s[12] == '0');
                answer += 1 - isSixty;
            }
        }
        return answer;
    }
};