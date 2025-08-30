class Solution {
    private int sx, ex, sy, ey; 
    private boolean check(int si, int ei, int sj, int ej, char[][] board){
        int[] checks = new int[10];
        for (int i = si; i < ei; i++)
        {
            for (int j = sj; j < ej; j++)
            {
                // System.out.print(board[i][j]);
                if (board[i][j] == '.') continue;
                // System.out.println(board[i][j] - '0');
                if (checks[board[i][j] - '0'] >= 1) return false;
                // System.out.print("g2" + checks[board[i][j] - '0']);
                checks[board[i][j] - '0']++;
                // System.out.print("g2" + checks[board[i][j] - '0']);
            }
            // System.out.println();
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++)
        {
            if (check(i, i + 1, 0, 9, board) == false) return false;
            if (check(0, 9, i, i + 1, board) == false) return false;
        }
        for (int i = 0; i < 9; i+= 3)
        {
            for (int j = 0; j < 9; j+= 3)
            {
                if (check(i, i + 3, j, j + 3, board) == false) return false;
            }
        }
        return true;
    }
}