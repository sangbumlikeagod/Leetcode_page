class Solution {
    public int maxProductPath(int[][] grid) {
        long MODULO = 1000000007;
        int m = grid.length;
        int n = grid[0].length;
        int[][][][] minusDP = new int[m][n][62][32];
        int[][][][] plusDP = new int[m][n][62][32];

        long answers = -1;
        if (grid[0][0] == 1)
        {
            plusDP[0][0][0][0] = 1;
        }
        else if (grid[0][0] == 2)
        {
            plusDP[0][0][1][0] = 1;
        }
        else if (grid[0][0] == 3)
        {
            plusDP[0][0][0][1] = 1;
        }
        else if (grid[0][0] == 4)
        {
            plusDP[0][0][2][0] = 1;
        }
        else if (grid[0][0] == -1)
        {
            minusDP[0][0][0][0] = 1;
        }
        else if (grid[0][0] == -2)
        {
            minusDP[0][0][1][0] = 1;
        }
        else if (grid[0][0] == -3)
        {
            minusDP[0][0][0][1] = 1;
        }
        else if (grid[0][0] == -4)
        {
            minusDP[0][0][2][0] = 1;
        }
        else
        {
            return 0;
        }
        int answer = -1;


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int p = 0; p <= (m + n) * 2; p++)
                {
                    for (int q = 0; q <= m + n; q++)
                    {
                        // 내가 2가 p개 3이 q개 있음

                        if (plusDP[i][j][p][q] == 1)
                        {

                            if (i != m - 1)
                            {
                                // 다음애가 0보다큼
                                if (grid[i + 1][j] > 0)
                                {
                                    if (grid[i + 1][j] == 1)
                                    {
                                        plusDP[i + 1][j][p][q] = 1;
                                    }
                                    else if (grid[i + 1][j] == 2)
                                    {
                                        plusDP[i + 1][j][p + 1][q] = 1;
                                    }
                                    else if (grid[i + 1][j] == 3)
                                    {
                                        plusDP[i + 1][j][p][q + 1] = 1;
                                    }
                                    else
                                    {
                                        plusDP[i + 1][j][p + 2][q] = 1;
                                    }
                                }
                                else
                                {
                                    if (grid[i + 1][j] == -1)
                                    {
                                        minusDP[i + 1][j][p][q] = 1;
                                    }
                                    else if (grid[i + 1][j] == -2)
                                    {
                                        minusDP[i + 1][j][p + 1][q] = 1;
                                    }
                                    else if (grid[i + 1][j] == -3)
                                    {
                                        minusDP[i + 1][j][p][q + 1] = 1;
                                    }
                                    else if (grid[i + 1][j] == -4)
                                    {
                                        minusDP[i + 1][j][p + 2][q] = 1;
                                    }
                                    else
                                    {
                                        answer = 0;
                                        answers = 0;
                                    }
                                }
                            }

                            if (j != n - 1)
                            {
                                 if (grid[i][j + 1] > 0)
                                {
                                    if (grid[i][j + 1] == 1)
                                    {
                                        plusDP[i][j + 1][p][q] = 1;
                                    }
                                    else if (grid[i][j + 1] == 2)
                                    {
                                        plusDP[i][j + 1][p + 1][q] = 1;
                                    }
                                    else if (grid[i][j + 1] == 3)
                                    {
                                        plusDP[i][j + 1][p][q + 1] = 1;
                                    }
                                    else
                                    {
                                        plusDP[i][j + 1][p + 2][q] = 1;
                                    }
                                }
                                else
                                {
                                    if (grid[i][j + 1] == -1)
                                    {
                                        minusDP[i][j + 1][p][q] = 1;
                                    }
                                    else if (grid[i][j + 1] == -2)
                                    {
                                        minusDP[i][j + 1][p + 1][q] = 1;
                                    }
                                    else if (grid[i][j + 1] == -3)
                                    {
                                        minusDP[i][j + 1][p][q + 1] = 1;
                                    }
                                    else if (grid[i][j + 1] == -4)
                                    {
                                        minusDP[i][j + 1][p + 2][q] = 1;
                                    }
                                    else
                                    {
                                        answer = 0;
                                        answers = 0;
                                    }
                                }
                            }
                        }

                        if (minusDP[i][j][p][q] == 1)
                        {
                            if (i != m - 1)
                            {
                                // 다음애가 0보다큼
                                if (grid[i + 1][j] > 0)
                                {
                                    if (grid[i + 1][j] == 1)
                                    {
                                        minusDP[i + 1][j][p][q] = 1;
                                    }
                                    else if (grid[i + 1][j] == 2)
                                    {
                                        minusDP[i + 1][j][p + 1][q] = 1;
                                    }
                                    else if (grid[i + 1][j] == 3)
                                    {
                                        minusDP[i + 1][j][p][q + 1] = 1;
                                    }
                                    else
                                    {
                                        minusDP[i + 1][j][p + 2][q] = 1;
                                    }
                                }
                                else
                                {
                                    if (grid[i + 1][j] == -1)
                                    {
                                        plusDP[i + 1][j][p][q] = 1;
                                    }
                                    else if (grid[i + 1][j] == -2)
                                    {
                                        plusDP[i + 1][j][p + 1][q] = 1;
                                    }
                                    else if (grid[i + 1][j] == -3)
                                    {
                                        plusDP[i + 1][j][p][q + 1] = 1;
                                    }
                                    else if (grid[i + 1][j] == -4)
                                    {
                                        plusDP[i + 1][j][p + 2][q] = 1;
                                    }
                                    else
                                    {
                                        answer = 0;
                                        answers = 0;
                                    }
                                }
                            }

                            if (j != n - 1)
                            {
                                 if (grid[i][j + 1] > 0)
                                {
                                    if (grid[i][j + 1] == 1)
                                    {
                                        minusDP[i][j + 1][p][q] = 1;
                                    }
                                    else if (grid[i][j + 1] == 2)
                                    {
                                        minusDP[i][j + 1][p + 1][q] = 1;
                                    }
                                    else if (grid[i][j + 1] == 3)
                                    {
                                        minusDP[i][j + 1][p][q + 1] = 1;
                                    }
                                    else 
                                    {
                                        minusDP[i][j + 1][p + 2][q] = 1;
                                    }
                                }
                                else
                                {
                                    if (grid[i][j + 1] == -1)
                                    {
                                        plusDP[i][j + 1][p][q] = 1;
                                    }
                                    else if (grid[i][j + 1] == -2)
                                    {
                                        plusDP[i][j + 1][p + 1][q] = 1;
                                    }
                                    else if (grid[i][j + 1] == -3)
                                    {
                                        plusDP[i][j + 1][p][q + 1] = 1;
                                    }
                                    else if (grid[i][j + 1] == -4)
                                    {
                                        plusDP[i][j + 1][p + 2][q] = 1;
                                    }
                                    else
                                    {
                                        answer = 0;
                                        answers = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= (m + n) * 2; i++)
        {
            for (int j = 0; j <= (m + n); j++)
            {
                if (plusDP[m - 1][n - 1][i][j] == 1)
                {
                    long arg = (long) 1 << (i);
                    long arg2 = arg;

                    arg %= MODULO;

                    for (int j2 = 0; j2 < j; j2++)
                    {
                        arg *= 3;
                        arg2 *= 3;
                        arg %= MODULO;
                    }
                    // System.out.println(i + " " + j + " " + arg);
                    answers = Math.max(answers, arg2);
                    answer = Math.max(answer, (int) arg);
                }
            }
        }
        return (int) (answers % MODULO);
    }
}