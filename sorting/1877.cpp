class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size() - 1;
        int maxval = 0;
        while (s < e)
        {
            if (nums[s] + nums[e] > maxval)
                maxval = nums[s] + nums[e];
            s++;
            e--;
        }
        return maxval;
    }
};