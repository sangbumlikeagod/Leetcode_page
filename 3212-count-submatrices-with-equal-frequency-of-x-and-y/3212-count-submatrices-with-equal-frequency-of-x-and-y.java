class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] xCols = new int[m + 1][n + 1];
        int[][] xRows = new int[m + 1][n + 1];

        int[][] yCols = new int[m + 1][n + 1];
        int[][] yRows = new int[m + 1][n + 1];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                xCols[i][j + 1] = xCols[i][j];
                yCols[i][j + 1] = yCols[i][j];
                if (grid[i][j] == 'X')
                {
                    xCols[i][j + 1] = xCols[i][j] + 1;

                }
                else if (grid[i][j] == 'Y')
                {
                    yCols[i][j + 1] = yCols[i][j] + 1;
                }
            }
        }
        
        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                xRows[i + 1][j] = xRows[i][j] + xCols[i][j];
                yRows[i + 1][j] = yRows[i][j] + yCols[i][j];
            }
        }

        int answer = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (xRows[i][j] >= 1 && xRows[i][j] == yRows[i][j])
                {
                    answer++;
                }  
            }
        }
        return answer;
    }
}