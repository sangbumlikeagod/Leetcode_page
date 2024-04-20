#include <vector>
#include <algorithm>

class Solution
{
    int dp[500];

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int tmp = 0;
        for (int i = 0; i < k; i++)
        {
            tmp = max(tmp, arr[i]);
            // ans += tmp;
            dp[i] = tmp * (i + 1);
        }

        for (int i = k; i < arr.size(); i++)
        {

            // 최고의 값을 찾기위해
            int tmp = 0;
            int tmpdp = 0;
            for (int j = 0; j < k; j++)
            {
                tmp = max(tmp, arr[i - j]);
                tmpdp = max(tmpdp, tmp * (j + 1) + dp[i - j - 1]);
            }
            dp[i] = tmpdp;
        }
        return dp[arr.size() - 1];
    }
};