class Solution {
    public int[][] rotateGrid(int[][] grid, int k) {
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        int m = grid.length, n = grid[0].length;
        int[][] answer = new int[m][n];

        int x = 0, y = 0;

        while (m > 0 && n > 0)
        {
            int[] moves = {m - 1, n - 1, m - 1, n - 1};
            List<int[]> args = new ArrayList<>();
            int sx = x, sy = y;
            // args.add(new int[] {sx, sy});
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < moves[i]; j++)
                {
                    sx += dx[i];
                    sy += dy[i];
                    args.add(new int[] {sx, sy});
                }
            }
            // args.stream().forEach((a) -> {System.out.println(Arrays.toString(a));});

            for (int i = 0; i < args.size(); i++)
            {
                int[] arg= args.get(i);
                int[] next = args.get((i + k) % args.size());
                answer[next[0]][next[1]] = grid[arg[0]][arg[1]];
            }
            x++; y++;
            m -= 2; n -= 2;
        }

        return answer;
    }
}