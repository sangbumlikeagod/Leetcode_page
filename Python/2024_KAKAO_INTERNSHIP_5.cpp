#include <string>
#include <vector>

using namespace std;

const int MODULO = 10007;
int dp[200001] = {0};
int solution(int n, vector<int> tops)
{
    int answer = 0;
    return answer;
    dp[0] = 1;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        if (i != 2 * n)
        {
            dp[i + 2] += dp[i];
            dp[i + 2] %= MODULO;
        }
        dp[i + 1] += dp[i];
        dp[i + 1] %= MODULO;

        if (i % 2 && tops[(i - 1) / 2])
        {
            dp[i + 1] += dp[i];
            dp[i + 1] %= MODULO;
        }
    }
    return dp[2 * n];
}