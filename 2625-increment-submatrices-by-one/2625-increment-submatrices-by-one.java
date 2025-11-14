class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] datas = new int[n][n];
        int[][] pys = new int[n][n];


        for (int[] query : queries)
        {
            for (int r = query[0]; r <= query[2]; r++)
            {
                pys[r][query[1]]++;
                if (query[3] + 1 != n)
                {
                    pys[r][query[3] + 1]--;
                }
            }


        }
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
            {
                tmp += pys[i][j];
                datas[i][j] = tmp;
            }
        }
        return datas;
    }
}