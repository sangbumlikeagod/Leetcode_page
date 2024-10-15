class Solution {
public:
    long long minimumSteps(string s) {
        long long answer = 0;

        int satisfied = 0;
        for (int i = 0; i < s.length() ; i++)
        {
            if (s[i] == '0')
            {
                answer += i - satisfied;
                satisfied++;
            }
        }
        return answer;
    }
};