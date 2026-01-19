class Solution {
    private void swapOnX(int[] a, int[] b) {
        if (a[0] > b[0])
        {
            int[] c = a;
            a = b;
            b = c;
        }
    }
    private void swapOnY(int[] a, int[] b) {
        if (a[1] > b[1])
        {
            int[] c = a;
            a = b;
            b = c;
        }
    }


    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int ans = 0;
        int n = bottomLeft.length;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int[] a = {bottomLeft[i][0], topRight[i][0]};
                int[] b = {bottomLeft[j][0], topRight[j][0]};

                swapOnX(a, b);
                if (a[1] <= b[0])
                {
                    continue;
                }

                int[] c = {bottomLeft[i][1], topRight[i][1]};
                int[] d = {bottomLeft[j][1], topRight[j][1]};
                swapOnY(c, d);
                if (c[1] <= d[0])
                {
                    continue;
                }

                int dx = Math.min(topRight[i][0], topRight[j][0]) - Math.max(bottomLeft[i][0], bottomLeft[j][0]);

                int dy = Math.min(topRight[i][1], topRight[j][1]) - Math.max(bottomLeft[i][1], bottomLeft[j][1]);
                ans =Math.max(ans, Math.min(dx, dy));

            }
        }
        return (long) ans * ans;



    }
}