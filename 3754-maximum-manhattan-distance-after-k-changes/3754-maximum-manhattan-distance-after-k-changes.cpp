class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> directions(4);
        int n = s.length();
        int answer = k;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == 'N')
            {
                directions[0]++;
            }
            else if (c == 'S')
            {
                directions[1]++;

            }
            else if (c == 'E')
            {
                directions[2]++;
            }
            else
            {
                directions[3]++;
            }
            int tmp = abs(directions[0] - directions[1]) + abs(directions[3] - directions[2]);
            if (i >= k)
            {
                int kC = k;
                if (directions[0] - directions[1] < 0)
                {
                    tmp += min(kC, directions[0]) * 2;
                    kC = max(kC - directions[0], 0);
                } 
                else
                {
                    tmp += min(kC, directions[1]) * 2;
                    kC = max(kC - directions[1], 0);
                }
                // cout << kC << '\n';
                if (directions[3] - directions[2] < 0)
                {
                    tmp += min(kC, directions[3]) * 2;
                }
                else
                {
                    tmp += min(kC, directions[2]) * 2;
                }
                // cout << i << ' ' << tmp << ' ' << answer << '\n'; 
            }
            answer = max(tmp, answer);
        }
        // 가로 
        // int answer = abs(directions[0] - directions[3]) + abs(directions[1] - directions[2]);
        // cout << answer << '\n';
        // if (directions[0] - directions[1] < 0)
        // {
        //     answer += min(k, directions[0]) * 2;
        //     k = max(k - directions[0], 0);
        // } 
        // else
        // {
        //     answer += min(k, directions[1]) * 2;
        //     k = max(k - directions[1], 0);
        // }
        // cout << k << '\n';
        // if (directions[3] - directions[2] < 0)
        // {
        //     answer += min(k, directions[3]) * 2;
        // }
        // else
        // {
        //     answer += min(k, directions[2]) * 2;
        // }
        return answer;
    }
};