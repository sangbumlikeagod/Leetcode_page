class Solution {
    private Queue<int[]> q = new LinkedList<>();
    private PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
    private int[] dx = {0, 0, 1, -1};
    private int[] dy = {1, -1, 0, 0};
    private int[][] palette;
    private int[][] visited;

    private boolean allowed(int nx, int ny)
    {
        int m = palette.length;
        return 0 <= nx && nx < m && 0 <= ny && ny < m;
    }

    
    private void draw()
    {
        while (!q.isEmpty())
        {
            int[] next = q.poll();
            for (int i = 0; i < 4; i++)
            {
                int nx = next[0] + dx[i];
                int ny = next[1] + dy[i];

                if (allowed(nx, ny) && visited[nx][ny] == 0) 
                {
                    palette[nx][ny] = palette[next[0]][next[1]] + 1; 
                    visited[nx][ny] = 1;
                    q.add(new int[] {nx, ny});
                }
            }
        }
    }


    private int travel()
    {
        while (!pq.isEmpty())
        {
            int[] next = pq.poll();
            // System.out.println(Arrays.toString(next));
            if (next[1] == palette.length - 1 && next[2] == palette[0].length - 1) {
                return next[0];
            }

            for (int i = 0; i < 4; i ++)
            {
                int nx = next[1] + dx[i];
                int ny = next[2] + dy[i];
                
                if (
                    allowed(nx, ny) && 
                    palette[nx][ny] > 0
                )
                {
                    int ne = Math.min(next[0], palette[nx][ny]);
                    if (visited[nx][ny] < ne)
                    {
                        visited[nx][ny] = ne;
                        pq.add(new int[] {ne, nx, ny});
                    }
                }
            }
        }
        return 0;
    }
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int m = grid.size();    
        visited = new int[m][m];
        palette = new int[m][m];
        int answer = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid.get(i).get(j) == 1)
                {
                    visited[i][j] = 1;
                    q.add(new int[] {i, j});
                }
            }
        }
        draw();
        // System.out.println(Arrays.deepToString(palette));
        visited = new int[m][m];
        visited[0][0] = palette[0][0];
        pq.add(new int[] {palette[0][0], 0, 0});
        answer = travel();
        return answer;

        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {

        //         int inherit = -1;
        //         if (i > 0)
        //         {
        //             inherit = Math.max(palette[i - 1][j], inherit);
        //         }
        //         if (j > 0)
        //         {
        //             inherit = Math.max(palette[i][j - 1], inherit);
        //         }

        //         // 부모 둘중 큰놈의 경로만을 따라간다 
        //         if (inherit != -1)
        //         {
        //             palette[i][j] = Math.min(inherit, palette[i][j]);
        //         }
        //     }
        // }
        // answer = palette[m - 1][m - 1];
        // return answer;
    }
}