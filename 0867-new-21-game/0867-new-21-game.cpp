class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double answer = 0.f;

        vector<double> dp(k + 2, 0.f);
        // 
        // dp[k - 1] = max((double) ((k - 1 + maxPts) - n )/ maxPts, (double) 0);

        for (int i = k - 1; i >= 0; i--)
        {
            // 모든뽑기중에서 1 + 2 - 2 반드시 클 확률
            double basic = max((double) ((i + maxPts) - n)/ maxPts, (double) 0);
            
            // basic이 0된순간부터 이상해지는데 
            int sI = i + 1;
            int eI = min(k, i + maxPts + 1);
            double pro = (double) 1 /(double) maxPts;
            double precedence = (dp[sI] - dp[eI]) * pro;
            // cout << i << " " << basic << " " << precedence << " " << pro << '\n';
            double mine = basic + precedence;
            dp[i] = dp[i + 1] + mine;
        }
        answer = dp[0] - dp[1];
        return 1 - answer;
    }
};