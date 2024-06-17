class Solution
{
    typedef long long ll;

public:
    int minPatches(vector<int> &nums, int n)
    {
        ll prefixSum = 1;
        int ans = 0;
        int index = 0;
        while (index < nums.size() && prefixSum <= n)
        {
            int next = nums[index];
            if (next <= prefixSum)
            {
                prefixSum += next;
                index++;
            }
            else
            {
                prefixSum *= 2;
                ans++;
            }
        }
        while (prefixSum <= n)
        {
            ans++;
            prefixSum *= 2;
        }
        return ans;
    }
};