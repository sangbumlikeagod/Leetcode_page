class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;

        int prev = grid[0][0];
        int[][] answer = new int[m][n];
        while (k != 0)
        {
            int last = grid[m - 1][n - 1];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j< n; j++)
                {   
                    int tmp = prev;
                    prev = grid[i][j];
                    answer[i][j] = tmp;
                }
            }
            answer[0][0] = last;
            grid=answer;
            answer = new int[m][n];
            k--;
        } 

        // System.out.println(Arrays.deepToString(grid));
        return Arrays.stream(grid).map(arr -> Arrays.stream(arr).boxed().toList()).toList();
    }
}