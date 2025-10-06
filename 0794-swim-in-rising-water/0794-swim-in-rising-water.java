class Solution {
    int[] dx = {0, 0, 1, -1};
    int[] dy = {1, -1, 0, 0};
    private boolean isPossible(int x, int y, int m)
    {
        return (0 <= x && x < m && 0 <= y && y < m);
    }

    private boolean bfs(int[][] grid, int limit)
    {
        Queue<Integer> queue = new LinkedList<>();
        int m = grid.length;
        queue.add(0);
        int[][] visited = new int[51][51];
        visited[0][0] = 1;
        while (queue.isEmpty() == false)
        {
            Integer next = queue.poll();
            int x = next / 50, y = next % 50;
            if (x == m - 1 && y == m - 1)
            {
                return true;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isPossible(nx, ny, m) && visited[nx][ny] == 0 && grid[nx][ny] <= limit)
                {
                    visited[nx][ny] = 1;
                    queue.add(nx * 50 + ny);
                }
            }   
        }
        return false;
    }
    public int swimInWater(int[][] grid) {
        int l = grid[0][0], r = 2500;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (bfs(grid, m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
}