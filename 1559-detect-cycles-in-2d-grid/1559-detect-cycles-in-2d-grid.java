class Solution {

    private boolean dfsCover(
        int id,
        int i,
        int j,
        int [][] visited,
        char[][] grid
    )
    {   
        
        return dfs(id, i, j, -1, -1, visited, grid);
    }
    private boolean dfs(
        int id,
        int i, int j,
        int li, int lj,
        int[][] visited,
        char[][] grid
    ) {
        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};
        int m = grid.length;
        int n = grid[0].length;
        

        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k], ny = j + dy[k];
            if (0 <= nx && nx < m && 0 <= ny && ny < n)
            {

                if (visited[nx][ny] == id && nx != li && ny != lj)
                {
                    
                    return true;
                }
                if (
                    visited[nx][ny] == 0 &&
                    grid[nx][ny] == grid[i][j]
                )
                {
                    visited[nx][ny] = id;
                    boolean res = dfs(
                        id,
                        nx, ny,
                        i, j,
                        visited, grid
                    );
                    if (res)
                    {
                        return true;
                    }
                }
            }
        }


        return false;
    }
    public boolean containsCycle(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] visited = new int[m][n];

        int id = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0)
                {
                    visited[i][j] = 1;
                    Boolean res = dfsCover(id++, i, j, visited, grid);
                    if (res)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}