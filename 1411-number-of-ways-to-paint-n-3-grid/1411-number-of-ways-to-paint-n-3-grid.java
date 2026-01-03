class Solution {
    long MODULO = 1000000007;
    String[] prerequisite ={"RYR", "YRY", "GRY", "RYG", "YRG", "GRG", "RGR", "YGR", "GYR", "RGY", "YGY", "GYG"};
    public int numOfWays(int n) {
        List<List<Integer>> adjList = new ArrayList<>();
        long[][] dp = new long[n + 1][12];

        for (int i = 0; i < 12; i++)
        {
            adjList.add(new ArrayList<>());
            dp[0][i] = 1;
        }
        for (int i = 0; i < 12; i++)
        {
            for (int j = i + 1; j < 12; j++)
            {
                boolean nonOverlap = true;
                for (int k = 0; k < 3; k++)
                {
                    if (prerequisite[i].charAt(k) == prerequisite[j].charAt(k))
                    {
                        nonOverlap= false;
                        break;
                    }
                }
                if (nonOverlap)
                {
                    adjList.get(i).add(j);
                    adjList.get(j).add(i);
                }
            }
        }
        for (int i = 0; i < 12; i++)
        {
            System.out.println(adjList.get(i));
        }
        long answer = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                for (int next : adjList.get(j))
                {
                    dp[i + 1][next] += dp[i][j];
                    dp[i + 1][next] %= MODULO;
                }
            }
        }

        for (int i = 0; i < 12; i++)
        {
            answer += dp[n - 1][i];
            answer %= MODULO;
        }

        return (int) (answer % MODULO);
    }
}