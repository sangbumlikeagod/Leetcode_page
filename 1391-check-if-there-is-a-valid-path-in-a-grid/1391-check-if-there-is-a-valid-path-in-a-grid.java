class Solution {
    // 왼쪽, 오른쪽, 위쪽, 아래쪽

    private boolean [][] adjPath = new boolean[][] 
    {
        {true, true, false, false},
        {false, false, true, true},
        {true, false, false, true},
        {false, true, false, true},
        {true, false, true, false},
        {false, true, true, false},
    };
    private int[] dx = new int[] {0, 0, -1, 1};
    private int[] dy = new int[] {-1, 1, 0, 0};


    private boolean dfs(int i, int j, int[][] grid, int[][] visited){
        int m = visited.length;
        int n = visited[0].length;
        // System.out.println(i + " " + j);
        if (i == m - 1 && j == n - 1)
        {
            return true;
        }
        int myCell = grid[i][j] - 1;

        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (
                0 <= nx && nx < m &&
                0 <= ny && ny < n &&
                visited[nx][ny] == 0 &&
                adjPath[myCell][k]
            )
            {
                int nextCell = grid[nx][ny] - 1;
                int nk;
                if (k == 0)
                {
                    nk = 1;
                }
                else if (k == 1)
                {
                    nk = 0;
                }
                else if (k == 2)
                {
                    nk = 3;
                }   
                else
                {
                    nk = 2;
                }
                if (adjPath[nextCell][nk])
                {

                    visited[nx][ny] = 1;
                    if (dfs(nx, ny, grid, visited))
                    {
                        return true;
                    }

                }
            }

        }


        return false;
    }
    public boolean hasValidPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] visited = new int[m][n];
        visited[0][0] = 1;

        return dfs(0, 0, grid, visited);

    }
}