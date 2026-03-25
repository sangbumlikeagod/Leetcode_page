class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        long[] rowPS = new long[m + 1];
        long[] columnPS = new long[n + 1];

        for (int i = 0; i < m; i++)
        {
            rowPS[i + 1] = rowPS[i];
            for (int j = 0; j < n; j++)
            {
                rowPS[i + 1] += grid[i][j];
            }
        }

        for (int j = 0; j < n; j++)
        {
            columnPS[j + 1] = columnPS[j];
            for (int i = 0; i < m; i++)
            {
                columnPS[j + 1] += grid[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (rowPS[i] * 2 == rowPS[m])
            {
                return true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (columnPS[i] * 2 == columnPS[n])
            {
                return true;
            }
        }
        return false;
    }
}