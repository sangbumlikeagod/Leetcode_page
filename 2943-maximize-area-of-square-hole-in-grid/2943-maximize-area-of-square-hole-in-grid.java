class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);
        int x = hBars.length;
        int y = vBars.length;

        int maxHLength = 0;
        int maxVLength = 0;

        int tmpHSegment = 1;
        int tmpVSegment = 1;
        for (int i = 1; i < x; i++)
        {

            if (hBars[i - 1] + 1 == hBars[i])
            {
                tmpHSegment++;
            }
            else
            {
                maxHLength = Math.max(maxHLength, tmpHSegment);   
                tmpHSegment = 1;
            }
        }
        maxHLength = Math.max(maxHLength, tmpHSegment);  

        for (int i = 1; i < y; i++)
        {
            System.out.println("??");
            if (vBars[i - 1] + 1 == vBars[i])
            {
                tmpVSegment++;
            }
            else
            {
                maxVLength = Math.max(maxVLength, tmpVSegment);   
                tmpVSegment = 1;
            }
        }

        maxVLength = Math.max(maxVLength, tmpVSegment);
        // System.out.println(maxVLength + " " + maxHLength);
        int ans = Math.min(maxVLength, maxHLength);
        return (ans + 1) * (ans + 1);
    }
}