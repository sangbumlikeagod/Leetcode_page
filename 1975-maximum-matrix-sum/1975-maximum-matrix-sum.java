class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int n = matrix.length;
        int minAbs = Integer.MAX_VALUE;
        int cnt = 0;
        long answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] <= 0)
                {
                    answer -= matrix[i][j];
                    cnt++;
                }
                else
                {
                    answer += matrix[i][j];
                }
                minAbs = Math.min(minAbs, Math.abs(matrix[i][j]));

            }
        }
        return cnt % 2 == 1 ? answer - 2 * minAbs : answer;

    }
}