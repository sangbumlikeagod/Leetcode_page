class Solution {

    private int[][] timeToBecomeWater;

    private int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    private int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    private boolean dfs(int r, int c, int time, int[][] visited)
    {
        int re = timeToBecomeWater.length;
        int ce = timeToBecomeWater[0].length;
        if (c == ce - 1) {return true;}
        // if (r != re - 1 && timeToBecomeWater[r + 1][c + 1] <= time  && visited[r + 1][c + 1] != 1)
        // {
        //     visited[r + 1][c + 1] = 1;
        //     if (dfs(r + 1, c + 1, time, visited))
        //     {
        //         return true;
        //     }
        // }
        // if (r != 0 && timeToBecomeWater[r - 1][c + 1] <= time  && visited[r - 1][c + 1] != 1)
        // {
        //     visited[r - 1][c + 1] = 1;
        //     if (dfs(r - 1, c + 1, time, visited))
        //     {
        //         return true;
        //     }
        // }
        // if (timeToBecomeWater[r][c + 1] <= time && visited[r][c + 1] != 1)
        // {
        //     visited[r][c + 1] = 1;
        //     if (dfs(r, c + 1, time, visited))
        //     {
        //         return true;
        //     }
        // }
        for (int i = 0; i < 8; i++)
            {
                int nr = r + dx[i], nc = c + dy[i];
                if (0 <= nr && nr < re && 0 <= nc && nc < ce &&
                    visited[nr][nc] != 1 &&
                    timeToBecomeWater[nr][nc] <= time
                )
                {
                    visited[nr][nc] = 1;
                    if (dfs(nr, nc, time, visited))
                    {
                        return true;
                    }
                }
            }

        
        
        return false;
    }
    private boolean findPossibleDFS(int time)
    {
        // 시작열은 0으로 고정
        int re = timeToBecomeWater.length;
        int ce = timeToBecomeWater[0].length;
        int[][] visited = new int[re][ce];
         for (int i = 0; i < re; i++)
         {
            if (timeToBecomeWater[i][0] <= time)
            {
                if (dfs(i, 0, time, visited))
                {
                    visited[i][0] = 1;
                    return true;
                }
            }
         }
        return false;
    }

    

    
    public int latestDayToCross(int row, int col, int[][] cells) {
        // initialize
        timeToBecomeWater = new int[row][col];
        int maxTime = cells.length;
        for (int i = 0; i < maxTime; i++)
        {
            timeToBecomeWater[cells[i][0] - 1][cells[i][1] - 1] = i + 1;
        }

        int l = 0, r = maxTime - 1;
        // binarysearch
        while (l < r)
        {
            int m = (l + r) / 2;
            if (findPossibleDFS(m + 1))
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