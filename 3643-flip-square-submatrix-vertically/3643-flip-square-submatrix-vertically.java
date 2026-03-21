class Solution {
    private void getData(int[][] grid, int r1, int r2, int cs, int ce)
    {
        for (int i = cs; i < ce; i++)
        {
            int tmp = grid[r1][i];
            grid[r1][i] = grid[r2][i];
            grid[r2][i] = tmp;
        }
    }
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        
        int cs = y, ce = y + k;
        int u = x, d = x + k - 1;
        while (u < d)
        {
            getData(grid, u, d, cs, ce);
            u++;
            d--;
        }

        
        return grid;
    }
}