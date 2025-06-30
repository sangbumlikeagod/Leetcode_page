class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        pair<int, int> before = {-1e9 - 9, 0}, current = {1e9 + 9, 0};
        int answer = 0, partial = 0;
        for (int i = 0; i < n; i++)
        {
            if (current.first == nums[i])
            {
                current.second++;
            }
            else 
            {
                if (before.first + 1 == current.first)
                {
                    answer = max(answer, current.second + before.second);
                }
                before = current;
                current = {nums[i], 1};
            }
        }
        if (before.first + 1 == current.first)
        {
            answer = max(answer, current.second + before.second);
        }

        return answer;
    }
};