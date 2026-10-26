class Solution {
    private int[] dx = {0, 0, 1, -1};
    private int[] dy = {1, -1, 0, 0};
    private int[][] visited;
    private int M;
    private int N;
    private boolean isSafe(int x, int y, int[][] grid){
        return 0 <= x && x < M && 
                0 <= y && y < N && 
                grid[x][y] != 0 &&
                visited[x][y] == 0;
    }
    public long dfs(int[][] grid, int x, int y) {
        long answer = 0; 
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isSafe(nx, ny, grid))
            {
                visited[nx][ny] = 1;
                answer += dfs(grid, nx, ny);
            }
        }
        answer += grid[x][y];
        return answer;
    }
    public int 
    countIslands(int[][] grid, int k)
    {
        M = grid.length;
        N = grid[0].length;
        
        visited = new int[M][N];
        int answer = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (
                    grid[i][j] != 0 &&
                    visited[i][j] == 0
                )
                {
                    visited[i][j] = 1;
                    if (dfs(grid, i, j) % k == 0)
                    {
                        answer++;
                    } 
                }
            }
        }
        return answer;
    }
}