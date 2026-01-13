class Solution {
    double error = 1e-5;

    private double SquaresDiff(int[][] squares, double height)
    {
        // 위 사각형, 아래 사각형
        double s1 = 0, s2 = 0;

        for (int[] square : squares)
        {
            int a = square[2];
            double yL = (double) square[1];
            double yH = (double) square[1] + a;


                s1 += Math.max(yH - Math.max(yL, height), 0) * a;
                s2 += Math.max(Math.min(height, yH) - yL, 0) * a;
        }
        // System.out.println(s1+ ": 사각1 " + s2 + ": 사각2 " + (s1 - s2));
        return s1 - s2;
    }
    public double separateSquares(int[][] squares) {

        double a = 0, b = 1e9; 
        while (a < b)
        {
            double m = (a + b) / 2;
            // System.out.println(m);
            double ret = SquaresDiff(squares, m);
            // System.out.println(ret);
            if (Math.abs(ret) <= error)
            {
                a = m;
                break;
            }
            if (ret < 0)
            {
                b = m - 1e-5;
            }
            else
            {
                a = m + 1e-5;
            }
        }
        
        double maxVal = 0;
        for (int[] square : squares)
        {
            if ((double) square[1] < a  && a < (double) square[1] + square[2])
            {
                // System.out.println(Arrays.toString(square));
                maxVal = 0;
                break;
            }
            else
            {
                if ((double) square[1] + square[2] < a)
                {
                    maxVal = Math.max((double) square[1] + square[2], maxVal);
                }
            }
        }
        // System.out.println(maxVal);
        return maxVal > 0 ? maxVal : a;
                
    }
}