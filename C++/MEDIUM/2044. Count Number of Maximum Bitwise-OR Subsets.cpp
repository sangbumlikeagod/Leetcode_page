class Solution
{
    int answer;
    int maxVal;
    int na = 0;
    void backTracking(int idx, int val, vector<int> &nums)
    {
        if (idx == na)
        {
            if (val == maxVal)
            {
                answer++;
            }
            return;
        }

        backTracking(idx + 1, val | nums[idx], nums);
        backTracking(idx + 1, val, nums);
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        maxVal = 0;
        answer = 0;
        na = nums.size();
        for (int num : nums)
        {
            maxVal |= num;
        }

        backTracking(0, 0, nums);
        return answer;
    }
};