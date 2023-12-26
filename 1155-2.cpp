class Solution {
    int MODULO = 1000000007;
    int dp[31][901] = {0, };
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target > 900) return 0;
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i * k; j++)
            {   
                for (int p = 1; p <= k; p++)
                {
                    if (j + p + (n - i) * k >= target){
                        if (i == 1) {dp[i][j] = 1;}

                        if (j + p <= target && i != n){
                        dp[i + 1][j + p] += dp[i][j];
                        dp[i + 1][j + p] %= MODULO;
                        }
                    }
                }  
            }
        }
        return dp[n][target];
    }
};