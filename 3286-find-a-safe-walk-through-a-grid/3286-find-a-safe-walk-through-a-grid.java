class Solution {
    private PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

    int[] dx = {1, -1, 0 ,0};
    int[] dy = {0, 0, 1, -1};

    private int[][] visited;
    private List<List<Integer>> maps;    

    private boolean isSafe(int x, int y)
    {
        int m = visited.length, n = visited[0].length;
        return 0 <= x && x < m && 0 <= y && y < n;
    }

    private int djkstra() {
        while (!pq.isEmpty())
        {
            int[] next = pq.poll();

            if (
                next[1] == visited.length - 1 && 
                next[2] == visited[0].length - 1    
            )
            {
                return next[0];
            }

            for (
                int i = 0; i < 4; i++
            )
            {
                int nx = next[1] + dx[i];
                int ny = next[2] + dy[i];
                
                if (isSafe(nx, ny) && visited[nx][ny] == 0)
                {
                    visited[nx][ny] = 1;
                    pq.add(new int[] {next[0] + this.maps.get(nx).get(ny), nx, ny});   
                }
            }
        }
        return -1;
    }
    public boolean findSafeWalk
    (List<List<Integer>> grid, int health) {
        int m = grid.size();
        int n = grid.get(0).size();
        maps = grid;
        visited = new int[m][n];
        visited[0][0] = 1;
        pq.add(new int[] {grid.get(0).get(0), 0, 0});
        return djkstra() < health;
    }
}