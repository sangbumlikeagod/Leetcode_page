class Solution {
    private int m;

    private boolean isValid(int x, int y)
    {
        return 0 <= x && x < m && 0 <= y && y < m;
    }
    public int maxCollectedFruits(int[][] fruits) {
        m = fruits.length;
        int[][] dp = new int[m][m];
        int[][] dp_x = new int[m][m];
        int[][] dp_y = new int[m][m];
        // 대각선 먼저 처리

        // 밑의 애. 
        // (0, 3), (1, 2), (2, 2), (3, 3) 
        dp[0][0] = fruits[0][0];
        for (int i = 0; i < m - 2; i++)
        {
            dp[i + 1][i + 1] = fruits[i + 1][i + 1] + dp[i][i];
        }
        // System.out.println(dp[m - 2][m - 2]);
        dp_y[0][m - 1] = fruits[0][m - 1];
        dp_x[m - 1][0] = fruits[m - 1][0];
        for (int i = 0; i < m - 1; i++)
        {
            int movable = i < (m - 1) / 2 ? i : m - 2 - i;
            boolean possibleOther = i < (m / 2);
            // System.out.println(i + " " + movable);
            for (int j = m - 1; j >= m - 1 - movable; j--)
            {
                int nx, ny;
                nx = i + 1; ny = j - 1;
                if (isValid(nx, ny))
                {
                    dp_y[nx][ny] = Math.max(fruits[nx][ny] + dp_y[i][j], dp_y[nx][ny]);

                }
                ny = j;
                dp_y[nx][ny] = Math.max(fruits[nx][ny] + dp_y[i][j], dp_y[nx][ny]);
                ny = j + 1;
                if (isValid(nx, ny))
                {
                    dp_y[nx][ny] = Math.max(fruits[nx][ny] + dp_y[i][j], dp_y[nx][ny]);
                }
            }
        } 
        for (int i = 0; i < m - 1; i++)
        {
            int movable = i < (m - 1) / 2 ? i : m - 2 - i;
            boolean possibleOther = i < (m / 2);
            for (int j = m - 1; j >= m - 1 - movable; j--)
            {
                int nx, ny;
                nx = j - 1; ny = i + 1;
                if (isValid(nx, ny))
                {
                    dp_x[nx][ny] = Math.max(fruits[nx][ny] + dp_x[j][i], dp_x[nx][ny]);
                }
                nx = j;
                dp_x[nx][ny] = Math.max(fruits[nx][ny] + dp_x[j][i], dp_x[nx][ny]);
                nx = j + 1;
                if (isValid(nx, ny))
                {
                    dp_x[nx][ny] = Math.max(fruits[nx][ny] + dp_x[j][i], dp_x[nx][ny]);
                }
            }
        } 
        // System.out.println(dp_y[m - 2][m - 1]);
        // System.out.println(dp_x[m - 1][m - 2]);
        return dp[m - 2][m - 2] + dp_y[m - 2][m - 1] + dp_x[m - 1][m - 2] + fruits[m - 1][m - 1];
    }
}