class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> maps;
        vector<int> answer {};
        for (int i = 0; i < digits.size(); i++ )
        {
            for (int j = 0; j < digits.size(); j++ )
            {
                if (i == j) continue;
                for (int k = 0; k < digits.size(); k++ )
                {
                    if (j == k || i == k) continue;
                    if (maps[digits[i] * 100 + digits[j] * 10 + digits[k]] != 0)
                        continue;
                    if (digits[i] != 0 && digits[k] % 2 == 0)
                    {
                        maps[digits[i] * 100 + digits[j] * 10 + digits[k]] = 1;
                        answer.push_back(digits[i] * 100 + digits[j] * 10 + digits[k]);
                    }
                }
            }
        }
        sort(answer.begin(), answer.end());
        return answer;


    }
};