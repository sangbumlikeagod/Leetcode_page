class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;
        
        int[] divides = new int[n + 1];
        Arrays.sort(items, (a, b) -> Integer.compare(a[1], b[1]));
        

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (items[j][0] % items[i][0] == 0)
                {
                    divides[i]++;
                }
            }
        }
        
        
        int answer = 0;
        int[][] dp = new int[n + 1][budget + 1];
        dp[0][budget] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = budget; j >= 0; j--)
            {
                if (dp[i][j] != 0 && j >= items[i][1])
                {
                    dp[i + 1][j - items[i][1]] = Math.max(
                        dp[i + 1][j - items[i][1]],
                        dp[i][j] + divides[i]
                    );
                }
                dp[i + 1][j] = Math.max(
                    dp[i + 1][j],
                    dp[i][j]
                );
            }
        }

    
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= budget; j++)
            {
                // if (i == n)
                {
                    answer = Math.max(
                        answer,
                        dp[i][j] + (j / items[0][1])
                    );
                }
            }
        }
        return answer - 1;
    }
}