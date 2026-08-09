class Solution {
    int[][] dp = new int[100][100];
    int[] prefixPlies;
    // 1 => 2 => 
    private int DP(int idx, int le, int mx)
    {
        if (idx >= le) return 0;
        if (dp[idx][mx] != 0)
        {
            return dp[idx][mx];
        }
        int maxVal = 0;
        for (int i = 1; i <= Math.min(le - idx, mx * 2); i++)
        {
            // 선택의 범위는 두배까지 갈 수 있지만 사실상 남은 값 
            // 지금 값과 내 선택의 두배중 큰놈
            int nextMx = Math.min(Math.max(mx, i), le - idx);
            // 쌓인만큼은 내꺼 
            int myShare = prefixPlies[idx + i] - prefixPlies[idx];
            int nMaxVal = (int) 1e6 + 7;
            // System.out.println(idx + " " + i + " " + myShare + "  " +  nextMx);
            for (int j = 1; j <= nextMx * 2; j++)
            {
                int nNextMx = Math.min(Math.max(nextMx, j), le - i - idx);
                // 내가 소비한 범위 + 얘내가 선택하는 범위 만큼 추가 소비
                nMaxVal = Math.min(nMaxVal, DP(idx + i + j, le, nNextMx));
            }
            // System.out.println("in idx:" + idx + " mx is " + mx + " when i take " + i + "items maximumValue is" +  (nMaxVal + myShare));
            maxVal = Math.max(maxVal, myShare + nMaxVal);
        }
        dp[idx][mx] = maxVal;
        return dp[idx][mx];
    }
    public int stoneGameII(int[] piles) {
        int le = piles.length;
        prefixPlies = new int[le + 1];
        for (int i = 1; i <= le; i++)
        {
            prefixPlies[i] = prefixPlies[i - 1] + piles[i - 1];
        }
        return DP(0, le, 1);
    }
}