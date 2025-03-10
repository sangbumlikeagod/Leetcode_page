class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        vector<vector<int>> answers(6, vector<int>(word.length() + 1, 0));
        long long answer = 0;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];


            for (int j = 0; j < 6; j++)
            {
                answers[j][i + 1] = answers[j][i];
            }

            if (c == 'i')
            {
                answers[1][i + 1]++;
            } 
            else if (c == 'a')
            {
                answers[2][i + 1]++;
            }
            else if (c == 'e')
            {
                answers[3][i + 1]++;
            }
            else if (c == 'u')
            {
                answers[4][i + 1]++;
            }
            else if (c == 'o')
            {
                answers[5][i + 1]++;
            }
            else
            {
                answers[0][i + 1]++;
            }
        }

        for (int i = 0; i <= word.length(); i++)
        {
            bool pass = true;
            int minn = 1000000;
            int left = 0, right = 1000000;
            for (int j = 0; j < 6; j++)
            {
                // answers[i][j] 자체는 얼마길래 이러지 지금 내가 2갠데, 1개는 확정이라면 1개일떄를 구해야지 
                int limit = j ? answers[j][i] - 1 : answers[j][i] - k - 1;
                // cout << ' ' << answers[j][i] << ' ' << limit << '\t';
                auto arg = answers[j].begin();
                if (j) 
                {
                    // 0부터 여기까지 된다는 뜻, 모음이 적어도 하나씩은 있을 수 있는 범위를 말하는 것 
                    arg = upper_bound(answers[j].begin(), answers[j].end(), limit);
                    right = min((int) (arg - answers[j].begin()), right);
                }
                else
                {
                    // 자음이 정확히 k개 있을 방법 5, k = 2라면 3을 찾아야함 거기부터 되고, 4일때부터 안됨 
                    arg = upper_bound(answers[j].begin(), answers[j].end(), limit);
                    auto arg2 = upper_bound(answers[j].begin(), answers[j].end(), limit + 1);
                    left = max((int) (arg - answers[j].begin()), left);
                    right = min(right, (int) (arg2 - answers[j].begin()));
                }

                if (arg == answers[j].end())
                {
                    pass = false;
                    break;
                }
                int nums = i - ((arg - answers[j].begin()) - 1);
                // cout << limit << '\t';
            }
            if (right > left && pass) answer += (right - left);
            // cout  << "( " << right << ' ' << left  << " ) " << '\n';
            // if (pass == true) answer += minn;
        }
        return answer;

    }
};