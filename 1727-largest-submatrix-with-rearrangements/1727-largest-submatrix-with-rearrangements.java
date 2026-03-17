class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[][] memo = new int[m + 1][n];

        int answer = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1)
                {
                    memo[i + 1][j] = memo[i][j];
                    memo[i + 1][j]++;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            Arrays.sort(memo[i + 1]);
            // System.out.println(Arrays.toString(memo[i + 1]));
            int tmp = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                tmp = Math.max(tmp, memo[i + 1][j] * (n - j));
            }
            answer = Math.max(answer, tmp);
        }
        return answer;
    }
}