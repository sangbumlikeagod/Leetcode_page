class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        vector<int> list{};

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (list.empty() || nums[list.back()] > num)
            {
                list.push_back(i);
            }
        }
        int m = nums.size() - 1;
        int n = list.size() - 1;
        int answer = 0;
        for (; m >= 0; m--)
        {
            while (!list.empty() && nums[m] >= nums[list[n]])
            {
                answer = max(answer, m - list[n]);
                list.pop_back();
                n--;
            }
        }
        return answer;
    }
};