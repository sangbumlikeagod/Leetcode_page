class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int answer = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (num != val)
            {
                answer++;
            }
            else
            {
                for (int j = nums.size() - 1; j > i; j--)
                {
                    if (nums[j] != val)
                    {
                        swap(nums[i], nums[j]);
                        answer++;
                        break;
                    }
                }
            }
        }
        return answer;
    }
};