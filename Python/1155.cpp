
class Solution {
    int MODULO = 1000000007;
    int N;
    int K;
    int dp[31][901] = {0, };
public:
    int DP(int n, int target){
        if (!n){
            if (!target) {return 1;}
            else {return 0;}
        }
        if (target < 0) { return 0; }
        if (dp[n][target]) return dp[n][target];
        int res = 0;
        for (int k = K; k; k--){
            res += DP(n - 1, target - k);
            res %= MODULO;
        }
        dp[n][target] = res;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        K = k;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i * k; j++)
            {   
                for (int p = 1; p <= k; p++)
                {
                    if (p + (n - i) * k > target){
                        dp[i][j + p] += dp[i][j];
                        dp[i][j + p] %= MODULO;
                    }
                }
                
            }

        }
        return dp[n][target];
    }
};