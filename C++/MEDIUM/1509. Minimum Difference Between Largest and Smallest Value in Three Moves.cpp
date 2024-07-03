class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int left[4] = {0};
        int right[4] = {0};
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;
        int initial = nums[rightPointer] - nums[leftPointer];

        if (rightPointer < 4)
        {
            return 0;
        }
        for (int i = 1; i < 4; i++)
        {
            left[i] = left[i - 1] + nums[leftPointer + 1] - nums[leftPointer];
            right[i] = right[i - 1] + nums[rightPointer] - nums[rightPointer - 1];
            leftPointer++;
            rightPointer--;
        }
        int ans = left[3] + right[0];
        ans = max(ans, left[2] + right[1]);
        ans = max(ans, left[1] + right[2]);
        ans = max(ans, left[0] + right[3]);
        return initial - ans;
    }
};