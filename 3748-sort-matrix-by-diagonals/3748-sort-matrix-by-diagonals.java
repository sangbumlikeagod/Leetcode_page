class Solution {
    private int n;

    private boolean isSafe(int x, int y){
        return (0 <= x && x < n && 0 <= y && y < n);
    }
    private void _sortMatrix(int[][] grid, int[][] answer, int x, int y, int direct)
    {
        ArrayList<Integer> ret = new ArrayList<>();
        ret.add(grid[x][y]);
        while (isSafe(x + 1, y + 1))
        {
            x++; y++;
            ret.add(grid[x][y]);
        }
        Collections.sort(ret, (Integer a, Integer b) -> {return (a - b) * direct;});
        // System.out.println(ret);

        answer[x][y] = ret.get(0);
        int idx = 1;
        while (isSafe(x - 1, y - 1))
        {
            x--; y--;
            answer[x][y] = ret.get(idx++);
        }
    }
    public int[][] sortMatrix(int[][] grid) {
        n = grid.length;
        int[][] answer = new int[n][n];
        
        for (int i = n - 1; i >= 0; i--)
        {
            _sortMatrix(grid, answer, i, 0, 1);
        }
        for (int j = 1; j < n; j++)
        {
            _sortMatrix(grid, answer, 0, j, -1);
        }
        return answer;
    }
}