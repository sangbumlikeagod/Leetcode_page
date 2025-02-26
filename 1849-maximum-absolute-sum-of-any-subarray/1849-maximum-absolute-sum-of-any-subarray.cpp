class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<pair<int, int>> acc {{0, 0}};
        for (int i = 0; i < nums.size(); i++)
        {
            auto& arg = acc.back();
            if (nums[i] > 0)
            {
                acc.push_back({arg.first + nums[i], min(arg.second + nums[i], 0)});
            }
            else
            {
                acc.push_back({max(arg.first + nums[i], 0), arg.second + nums[i]});
            }

        } 
        int answer = 0;
        for (auto& arg : acc)
        {
            answer = max(answer, max(arg.first, -1 * arg.second)); 
        }
        return answer;
    }
};