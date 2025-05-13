class Solution {
    int MODULO = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> digits (26);
        vector<long long> digits2 (26);

        for (char c : s)
        {
            digits[c - 'a']++;
        }
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (j == 25)
                {
                   digits2[0] += digits[j];
                   digits2[0] %= MODULO;
                   digits2[1] += digits[j];
                   digits2[1] %= MODULO;
                }
                else
                {
                    digits2[j + 1] += digits[j];
                    digits2[j + 1] %= MODULO;
                }
                digits[j] = 0;
            }
            swap(digits, digits2);
        }
        int answer = 0;
        for (int i = 0; i < 26; i++)
        {
            answer += digits[i];
            answer %= MODULO;
        }
        return answer;
    
    }
};