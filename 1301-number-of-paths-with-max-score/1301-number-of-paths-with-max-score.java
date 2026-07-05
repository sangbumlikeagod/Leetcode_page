class Solution {
    private final long MODULO = (long) 1e9 + 7;
    private long[][][] DP;
    private int[] dx = {-1, 0, -1};
    private int[] dy = {0, -1, -1};
    private int MAXSUM = 1800;
    private boolean isSafe(int i, int j, int m) {
            return 0 <= i && i < m && 0 <= j && j < m;
        }

    // private long[][][] DP_PATH = 
    public int[] pathsWithMaxScore(List<String> board) {
        int m = board.size();
        MAXSUM = m * 2 * 9;
        DP = new long[m][m][MAXSUM + 1];
        int[] answer = new int[] {0, 0};


        DP[m - 1][m - 1][0] = 1;
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                for (int k = 0; k <= MAXSUM; k++)
                {
                    if (DP[i][j][k] != 0)
                    {
                        for (int d = 0; d < 3; d++)
                        {

                            int nx = i + dx[d];
                            int ny = j + dy[d];
                            if (
                                isSafe(nx, ny, m) &&
                                board.get(nx).charAt(ny) != 'X'
                            )
                            {
                                int nk = k;
                                if (board.get(nx).charAt(ny) != 'E')
                                {
                                    nk += board.get(nx).charAt(ny) - '0';
                                }
                                DP[nx][ny][nk] += DP[i][j][k];
                                DP[nx][ny][nk] %= MODULO;
                            }
                        }
                    }
                }
            }
        }

        for (int i = MAXSUM; i >= 0; i--)
        {
            if (DP[0][0][i] != 0)
            {
                answer[0] = i;
                answer[1] = (int) (DP[0][0][i] % MODULO);
                break;
            }
        }

        return answer;
        

    }
}