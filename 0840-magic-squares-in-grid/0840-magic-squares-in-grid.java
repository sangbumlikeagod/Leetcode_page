class Solution {
    private boolean detectDuplucate(int i, int j, int[][] grid)
    {
        int[] detected = new int[10];
        for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                    {
                        if (grid[x][y] > 9 || grid[x][y] == 0)
                        {
                            return false;
                        }
                        if (detected[grid[x][y]] == 1)
                        {
                            // System.out.println("no1 " + i + " " + j);
                            return false;
                        }
                        detected[grid[x][y]] = 1;
                    }
            }
        return true;
    }
    private int getRowSum(int i, int j, int[][] grid)
    {
        return grid[i][j + 0] + grid[i][j + 1] + grid[i][j + 2];
    }
    
    private int getColumnSum(int i, int j, int[][] grid)
    {
        return grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
    }
    
    private boolean validMagicMatrix(int i, int j, int[][] grid)
    {
        if (grid[i + 1][j + 1] != 5)
        {
            // System.out.println("no 2");
            return false;
        }
        for (int x = 0; x < 3; x++)
            {
                if (getRowSum(i + x, j, grid) != 15 || getColumnSum(i, j + x, grid) != 15)
                {
                    // System.out.println("now");
                    return false;
                }            
                    
            }

        if (
            grid[i][j] + grid[i + 2][j + 2] != 10 ||
            grid[i][j + 2] + grid[i + 2][j] != 10
           
        ){
            // System.out.println("no3");
            return false;
        }
        return true;

        
    }
    
    public int numMagicSquaresInside(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        if (m < 3 || n < 3) return 0;
        int answer = 0;
        for (int i = 0; i < m - 2; i++)
            {
                for (int j = 0; j < n - 2; j++)
                    {
                        if (detectDuplucate(i, j, grid) && validMagicMatrix(i, j, grid))
                        {
                            answer++;
                        }
                    }
            }
        return answer;
    }
}