class Solution {
    int MODULO = 1000000000 + 7;
public:
    int numTilings(int n) {
        vector<vector<int>> dominos (n + 2, vector<int>(3, 0));
        dominos[1][0] = 1;
        dominos[2][0] = 1;
        dominos[1][1] = 1;
        dominos[1][2] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (dominos[i][j] != -1)
                {
                    // cout << i << ' ' << j << ' ' << dominos[i][j] << '\n';

                    if (j == 0)
                    {
                        dominos[i + 1][0] += dominos[i][j];
                        dominos[i + 1][0] %= MODULO;

                        dominos[i + 2][0] += dominos[i][j];
                        dominos[i + 2][0] %= MODULO;

                        dominos[i + 1][1] += dominos[i][j];
                        dominos[i + 1][1] %= MODULO;
                        dominos[i + 1][2] += dominos[i][j];
                        dominos[i + 1][2] %= MODULO;
                        // cout << '\t' << i << ' ' << j << ' ' << dominos[i][j] << '\n';
                    }
                    else if (j == 1)
                    {
                        // 위에만 비었어
                        dominos[i + 2][0] += dominos[i][j];
                        dominos[i + 2][0] %= MODULO;
                        dominos[i + 1][2] += dominos[i][j];
                        dominos[i + 1][2] %= MODULO;
                    }
                    else
                    {
                        // 아래만 비었어
                        dominos[i + 2][0] += dominos[i][j];
                        dominos[i + 2][0] %= MODULO;
                        dominos[i + 1][1] += dominos[i][j];
                        dominos[i + 1][1] %= MODULO;
                    }

                    // cout << '\t' << dominos[n][0] << '\n';
                }
            }
        }
        return dominos[n][0];
    }
};