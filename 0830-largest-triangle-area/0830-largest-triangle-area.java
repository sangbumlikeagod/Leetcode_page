class Solution {
    private boolean checkGraduality(int[] a, int[] b, int[] c) {
        int dxAB = a[0] - b[0];
        int dyAB = a[1] - b[1];
        int dxAC = a[0] - c[0];
        int dyAC = a[1] - c[1];
        int dxBC = b[0] - c[0];
        int dyBC = b[1] - c[1];
        return ((dxAB * dyAC == dxAC * dyAB) ||
            (dxAB * dyBC == dxBC * dyAB) ||
        (dxAC * dyBC == dxBC * dyAC));
    }

    private double getHeightWidth(int[] a, int[] b, int[] c)
    {
        // double answer = 0;
        int dxAB = a[0] - b[0];
        int dyAB = a[1] - b[1];

        double ab = Math.sqrt((double) (dxAB * dxAB + dyAB * dyAB));

        double gradAB = (double)dyAB / dxAB;

        double k = (double) c[1] + ((double) c[0] / gradAB);

        double abC = (double) a[1] - gradAB * (double) a[0];


        double nx = (k - abC) / (gradAB + 1 / gradAB);
        double ny = gradAB * nx + abC;


        double height = Math.sqrt((double) (nx - c[0]) * (nx - c[0]) + (ny - c[1]) * (ny - c[1]));

        return height * ab / 2;
    }
    
    private double coveredRectangle(int[] a, int[] b, int[] c)
    {
        double answer = 0;
        int minx = Math.min(a[0], b[0]);
        minx = Math.min(minx, c[0]);

        int miny = Math.min(a[1], b[1]);
        miny = Math.min(miny, c[1]);

        int maxx = Math.max(a[0], b[0]);
        maxx = Math.max(maxx, c[0]);

        int maxy = Math.max(a[1], b[1]);
        maxy = Math.max(maxy, c[1]);


        answer = (double) ((maxy - miny) * (maxx - minx));
        answer -= ((double) (Math.abs(a[0] - b[0]) * Math.abs(a[1] - b[1]))) / 2;
        answer -= ((double) (Math.abs(c[0] - b[0]) * Math.abs(c[1] - b[1]))) / 2;
        answer -= ((double) (Math.abs(a[0] - c[0]) * Math.abs(a[1] - c[1]))) / 2;
        
        return answer;
    }
    public double largestTriangleArea(int[][] points) {
        double answer = 0;
        int s = points.length;
        for (int i = 0; i < s - 2; i++)
        {
            for (int j = i + 1; j < s - 1; j++)
            {
                for (int k = j + 1; k < s; k++)
                {
                    if (checkGraduality(points[i], points[j], points[k]))
                    {
                        continue;
                    }

                                                            
                    if (points[i][0] -  points[j][0] != 0 && points[i][1] - points[j][1] != 0)
                    {
                        answer = Math.max(answer, getHeightWidth(points[i], points[j], points[k]));
                    }
                    else if (points[i][0] -  points[k][0] != 0 && points[i][1] - points[k][1] != 0){
                        answer = Math.max(answer, getHeightWidth(points[i], points[k], points[j]));
                    }
                    else
                    {
                        answer = Math.max(answer, getHeightWidth(points[j], points[k], points[i]));
                    }
                }
            }
        }
        return answer;
    }
}