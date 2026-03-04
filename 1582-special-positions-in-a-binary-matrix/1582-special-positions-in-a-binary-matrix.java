class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length, n = mat[0].length;

        int[] colCount = new int[n];
        int[] rowCount = new int[m];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1)
                {
                    answer++;
                }
            }
        }
        return answer;
    }
}