class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums[0] < nums[1])
        {
            nums[1] += nums[0];
        }
        int answer = nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                if (nums[i] < nums[i + 1])
                {
                    nums[i + 1] += nums[i];
                }
            }
            else
            {
                if (nums[i] - nums[i - 1] < nums[i + 1])
                { 
                    nums[i + 1] += nums[i];
                }
            }
            answer = max(answer, nums[i]);
        }
        answer = max(answer, nums.back());
        return answer;
    }
};