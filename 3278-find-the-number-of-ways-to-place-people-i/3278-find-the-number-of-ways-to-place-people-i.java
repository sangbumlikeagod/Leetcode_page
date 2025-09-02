class Solution {
    private boolean _numberOfPairs(int lx , int ex , int ly , int ey, int tx, int ty) 
    {
        return (lx <= tx && tx <= ex) && (ly <= ty && ty <= ey);
    }
    public int numberOfPairs(int[][] points) {
        int m = points.length;
        int answer = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                int lx = -1, ex = -1, ly = -1, ey = -1;
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1])
                {
                    lx = points[i][0]; ex = points[j][0]; ly = points[j][1]; ey = points[i][1];
                }
                else if (points[i][0] >= points[j][0] && points[i][1] <= points[j][1])
                {
                    lx = points[j][0]; ex = points[i][0]; ly = points[i][1]; ey = points[j][1];
                }
                if (lx != -1)
                {
                    boolean flag = true;
                    for (int k = 0; k < m; k++)
                    {
                        if (k == i || k == j) continue;
                        if (_numberOfPairs(lx, ex, ly, ey, points[k][0], points[k][1]))
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
}