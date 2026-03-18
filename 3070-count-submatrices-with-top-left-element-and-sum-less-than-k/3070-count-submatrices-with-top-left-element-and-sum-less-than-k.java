class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] cols = new int[m + 1][n + 1];
        int[][] rows = new int[m + 1][n + 1];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cols[i][j + 1] = cols[i][j] + grid[i][j];
            }
        }
        
        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                rows[i + 1][j] = rows[i][j] + cols[i][j];
            }
        }

        int answer = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (rows[i][j] <= k)
                {
                    answer++;
                }  
            }
        }
        return answer;
    }
}