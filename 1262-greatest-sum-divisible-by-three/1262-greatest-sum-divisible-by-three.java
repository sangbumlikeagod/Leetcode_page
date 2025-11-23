class Solution {
    public int maxSumDivThree(int[] nums) {
        int n = nums.length;
        int[][] DP = new int[2][3];

        DP[0][nums[0] % 3] = nums[0];
        for (int i = 1; i < n; i++)
            {
                int remainder = nums[i] % 3;
                DP[1][0] = DP[0][0];
                DP[1][1] = DP[0][1];
                DP[1][2] = DP[0][2];
                // 없는애들한테도 붙어버리는게 문제라고? 
                // System.out.println(Arrays.toString(DP[1]));
                if (DP[1][0] != 0)
                {
                    DP[0][remainder] = Math.max(DP[0][remainder], DP[1][0] + nums[i]);
                }
                if (DP[1][1] != 0 )
                {
                    DP[0][(remainder + 1) % 3] = Math.max(DP[0][(remainder + 1) % 3], DP[1][1] + nums[i]);
                }
                if (DP[1][2] != 0)
                {
                    DP[0][(remainder + 2) % 3] = Math.max(DP[0][(remainder + 2) % 3], DP[1][2] + nums[i]);
                }
                DP[0][remainder] = Math.max(DP[0][remainder], nums[i]);
                // System.out.println(Arrays.toString(DP[0]));
                // System.out.println();

            }

        return DP[0][0];
    }
}