
#define Xencode(x, y) ((int)pow(6, (x) * 3 + (y)))

/*
[0, 1, 2]
[3, 4, 5]
 */

class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int matchNum;
    queue<int> q;
    queue<int> nq;
public:
    void log(int n)
    {
        while (n)
        {
            cout << n % 6 << ' ';
            n /= 6;
        }
        cout << '\n';
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        matchNum = pow(6, 4) * 5 + pow(6, 3) * 4 + pow(6, 2) * 3 + pow(6, 1) * 2 + pow(6, 0) * 1;
        int initNum = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                initNum += pow(6, (i * 3 + j)) * board[i][j];
            }
        }
        vector<int> dp(pow(6, 6), 0);
        int answer = 0;
        dp[initNum] = 1;
        q.push(initNum);
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            // log(n);
            if (n == matchNum)
            {
                return answer;
            }

            int x, y;
            int tmp = n;
            for (int i = 0; i < 6; i++)
            {
                if (!(tmp % 6))
                {
                    x = i / 3, y = i % 3;
                    break;
                }
                tmp /= 6;
            }
            // cout << x << ' ' << y << '\n';
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nNum;
                if (0 <= nx && nx < 2 && 0 <= ny && ny < 3)
                {
                    if (nx == 0 && ny == 0)
                    {
                        // cout << (initNum % 6) * (Xencode(x, y) - Xencode(nx, ny)) << '\n';
                        nNum = n + (n % 6) * (Xencode(x, y) - Xencode(nx, ny));
                    }
                    else
                    {
                        nNum = n + (n / Xencode(nx, ny) % 6) * (Xencode(x, y) - Xencode(nx, ny));
                    }
                    if (!dp[nNum])
                    {
                        dp[nNum] = 1;
                        nq.push(nNum);
                    }
                }
            }
            if (q.empty())
            {
                answer++;
                swap(q, nq);
            }
        }

        return -1;
    }
};