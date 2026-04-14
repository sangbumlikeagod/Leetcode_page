class Solution {
    Long MAXIMUM = (long) 1e13;



    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        Collections.sort(robot);
        // List<int[]> newFactory = new ArrayList<>(); 
        List<Integer> newNewFactory = new ArrayList<>(); 
        for (int[] fac : factory)
        {
            for (int j = 0; j < fac[1]; j++)
            {
                newNewFactory.add(fac[0]);
            }
        }

        Collections.sort(newNewFactory);
        
        int fn = newNewFactory.size();
        int n = robot.size();

        long[][] DP = new long[n + 1][fn + 1];


        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= fn; j++)
            {
                DP[i][j] = MAXIMUM;
            }
        }
        for (int j = 0; j < fn; j++)
        {
            DP[0][j] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            // 아님 여기서 prefixSum을 쓰나? 근데 그것도 이상한데 
            for (int j = 0; j < fn; j++)
            {
                // 너가 얘좀 처리할래? 하고 미룬상태임
                DP[i][j + 1] = Math.min(
                    DP[i][j + 1], DP[i][j]
                );

                // 야 내가 처리할게 로 하고 
                DP[i + 1][j + 1] = Math.min(
                    DP[i + 1][j + 1],
                    DP[i][j] + Math.abs(robot.get(i) - newNewFactory.get(j))
                );

            }
        }


        long answer = MAXIMUM;
        for (int j = 0; j <= fn; j++)
        {
            answer = Math.min(answer, DP[n][j]);
        }
        return answer;
    }
}