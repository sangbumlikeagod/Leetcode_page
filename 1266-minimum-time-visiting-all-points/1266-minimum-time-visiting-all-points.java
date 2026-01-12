class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int n = points.length;
        int answer = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int[] point = points[i];
            int[] nPoint = points[i + 1];

            int df1 = Math.abs(nPoint[0] - point[0]);
            int df2 = Math.abs(nPoint[1] - point[1]);

            answer += df1 + df2 - Math.min(df1, df2);
        }
        return answer;
    }
}