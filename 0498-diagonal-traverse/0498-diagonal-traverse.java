class Solution {
    private int i = 0;
    private int j = 0;
    private int idx = 0;
    private int dx = -1;
    private int dy = 1;
    private int lx = 0;
    private int ly = 0;
    private void cycles(int[][] mats, int dir, int[] answer)
    {
        while (true) 
        {
            boolean isMove = false;
            
            answer[idx++] = mats[i][j];
            if (i + dx * dir != -1 && i + dx * dir != lx && j + dy * dir != -1 && j + dy * dir != ly)
            {
                i += dx * dir;
                j += dy * dir;
                isMove = true;
            }

            {
                if (i == 0 || i == lx - 1 || j == 0 || j == ly - 1)
                {
                    if (isMove)
                    {
                        answer[idx++] = mats[i][j];
                    }
                    break;
                }
            }
            
        }
        if (i == 0)
        {
            if (j == ly - 1)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        else if (i == lx - 1)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    public int[] findDiagonalOrder(int[][] mat) {
        lx = mat.length;
        ly = mat[0].length;
        
        int[] answer = new int[lx * ly];
        answer[0] = mat[0][0];
        if (lx * ly == 1) return answer;
        answer[lx * ly - 1] = mat[lx - 1][ly - 1];
        int dir = 1;

        while (i != lx - 1 || j != ly - 1)
        {
            cycles(mat, dir, answer);
            dir = dir == -1 ? 1 : -1;
        }

        return answer;
    }
}