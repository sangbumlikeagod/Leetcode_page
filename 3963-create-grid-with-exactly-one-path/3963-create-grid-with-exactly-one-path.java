class Solution {
    public String[] createGrid(int m, int n) {
        String[] answer = new String[m];
        for (int i = 0; i < m; i++)
        {
            StringBuffer sb = new StringBuffer();
            for (int j = 0; j < n; j++)
            {
                // 
                if (i == j)
                {
                    sb.append('.');
                }
                else if (i != m -1 && j == i + 1)
                {
                    sb.append('.');
                }
                else if (m <= n && i == m - 1 && j >= m)
                {
                    sb.append('.');
                }
                else if (m > n && i >= n && j == n - 1)
                {
                    sb.append('.');
                }
                else
                {
                    sb.append('#');
                }
            }
            answer[i] = sb.toString();
        }

        return answer;
    }
}