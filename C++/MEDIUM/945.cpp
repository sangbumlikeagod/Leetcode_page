class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int index = 1; index < nums.size(); index++)
        {
            while (nums[index] <= nums[index - 1])
            {
                ans++;
                nums[index]++;
            }
        }
        return ans;
    }
};