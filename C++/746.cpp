#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        class_cost = cost;
        visited = vector<int>(cost.size(), 0);
        dp(0);
        // int dp1 = dp(1);
        if (visited[0] >= visited[1])
        {
            return visited[1];
        }
        else
        {
            return visited[0];
        }
    }
    int dp(int idx)
    {
        // cout << idx << ' ' << class_cost.size() << endl;

        if (idx >= class_cost.size())
        {
            return 0;
        }
        if (visited[idx])
        {
            return visited[idx];
        }
        int res = 9999999;
        int dp1 = dp(idx + 1);
        if (res > dp1)
        {
            res = dp1;
        }
        int dp2 = dp(idx + 2);
        if (res > dp2)
        {
            res = dp2;
        }

        visited[idx] = res + class_cost[idx];
        return visited[idx];
    }

private:
    vector<int> class_cost;
    vector<int> visited;
};