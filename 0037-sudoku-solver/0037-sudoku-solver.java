class Solution {
    private int[][] xAxis = new int[9][9];
    private int[][] yAxis = new int[9][9];
    private int[][] squareAxis = new int[9][9];
    private ArrayList<ArrayList<Integer>> nums = new ArrayList<>();

    private  boolean backtracking(int idx, char[][] board)
    {
        if (idx == nums.size())
        {
            return true;
        }
        int x = nums.get(idx).get(0);
        int y = nums.get(idx).get(1);
        // System.out.println(x + " " + y + " "+ nums.size());
        for (int i = 0; i < 9; i++)
        {

            if (xAxis[x][i] != 0)
            {
                continue;
            }
            if (yAxis[y][i] != 0)
            {
                continue;
            }
            if (squareAxis[(x / 3) * 3 + (y / 3)][i] != 0)
            {
                continue;
            } 
            // System.out.println("\t" + idx + " " + i);
            xAxis[x][i]++;
            yAxis[y][i]++;
            squareAxis[(x / 3) * 3 + (y / 3)][i]++;
            if (backtracking(idx + 1, board))
            {
                board[x][y] = (char) ((int) '1' + i);
                return true;
            }
            xAxis[x][i]--;
            yAxis[y][i]--;
            squareAxis[(x / 3) * 3 + (y / 3)][i]--;
            continue;
        }
        return false;
    }

    public void solveSudoku(char[][] board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    char ac = board[i][j];
                    xAxis[i][ac - '1']++;
                    yAxis[j][ac - '1']++;
                    squareAxis[(i / 3) * 3 + (j / 3)][ac - '1']++;
                }
                else
                {
                    nums.add(new ArrayList<>(Arrays.asList(i, j)));
                }
            }
        }
        backtracking(0, board);
        System.out.println(nums);
    }
}