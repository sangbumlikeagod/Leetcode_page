class Solution
{
public:
    string shortestPalindrome(string s)
    {
        if (s.length() == 0)
        {
            return s;
        }
        vector<char> manacher;

        int right = -1;
        int center = -1;
        int maxCenter = 0;
        int maxWing = 0;
        int K = s.length() * 2 - 1;
        vector<int> palin(K, 0);

        // manacher.push_back('#');
        for (char c : s)
        {
            manacher.push_back(c);
            manacher.push_back('#');
        }
        manacher.pop_back();
        // 모든 제대로된 문자인덱스들은 짝수

        for (int i = 0; i < K; i++)
        {
            if (i < right)
            {
                // 왼쪽 끝은
                palin[i] = min(palin[center - (i - center)], K - i - 1);
            }
            int wing = palin[i];
            while (i - wing - 1 >= 0 && i + wing + 1 < K && manacher[i + wing + 1] == manacher[i - wing - 1])
            {
                wing++;
            }
            palin[i] = wing;
            if (i + wing > right)
            {
                right = i + wing;
                center = i;
            }
            if (i - wing == 0)
            {
                maxCenter = i;
                maxWing = wing;
            }
        }

        string answer;
        int limitIndex = maxCenter % 2 ? maxWing : maxCenter / 2 + maxWing / 2;
        for (int i = s.length() - 1; i > limitIndex; i--)
        {
            answer += s[i];
        }
        answer += s;
        return answer;
    }
};