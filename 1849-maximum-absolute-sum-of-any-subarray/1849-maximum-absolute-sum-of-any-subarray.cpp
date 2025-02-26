class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<vector<int>> acc (nums.size() + 1, {0, 0});
        for (int i = 0; i < nums.size(); i++)
        {
            auto& arg = acc[i];
            if (nums[i] > 0)
            {
                acc[i + 1] = {arg[0] + nums[i], min(arg[1] + nums[i], 0)};
            }
            else
            {
                acc[i + 1] = {max(arg[0] + nums[i], 0), arg[1] + nums[i]};
            }

        } 
        int answer = 0;
        for (auto& arg : acc)
        {
            answer = max(answer, max(arg[0], -1 * arg[1])); 
        }
        return answer;
    }
};