class Solution
{
    vector<vector<long long>> DP;

public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        DP = vector<vector<long long>>(nums.size(), {-1, -1});
        return dp(nums, k, 0, 0);
    }

private:
    long long dp(vector<int> &nums, int k, int node, int type)
    {
        if (node == nums.size())
        {
            return type ? INT_MIN : 0;
        }
        if (DP[node][type] != -1)
        {
            return DP[node][type];
        }

        long long nonXor = (nums[node] ^ (k * type)) + dp(nums, k, node + 1, 0);
        long long Xor = (nums[node] ^ (k * (type ^ 1))) + dp(nums, k, node + 1, 1);
        return DP[node][type] = max(nonXor, Xor);
    }
};