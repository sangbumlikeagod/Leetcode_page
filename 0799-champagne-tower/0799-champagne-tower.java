class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        int[][] layer = new int[101][101];
        double[][] memo = new double[101][101];

        layer[0][0] = 1;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                layer[i + 1][j] += layer[i][j];
                layer[i + 1][j + 1] += layer[i][j];
            }
        }


        memo[0][0] = (double) poured;
        for (int i = 0; i <= query_row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (memo[i][j] > (double) 1)
                {
                    double devided = (memo[i][j] - (double) 1)/ 2;
                    memo[i + 1][j] += devided;
                    memo[i + 1][j + 1] += devided;
                }
            }
        }
        return Math.min(memo[query_row][query_glass], 1.0);
    }
}