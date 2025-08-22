class Solution {
    public int minimumArea(int[][] grid) {
        int[] nsew= new int[4];
        nsew[0] = nsew[3] = 1001;
        
        int m = grid.length, n = grid[0].length;
        int answer = 9;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    nsew[0] = Math.min(nsew[0], i);
                    nsew[1] = Math.max(nsew[1], i);
                    nsew[2] = Math.max(nsew[2], j);
                    nsew[3] = Math.min(nsew[3], j);
                }
            }
        }
        return (nsew[1] - nsew[0] + 1) * (nsew[2] - nsew[3] + 1);
    }
}