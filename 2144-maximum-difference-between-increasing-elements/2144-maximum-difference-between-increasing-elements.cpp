class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        for (int i = 0 ; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                answer = max(answer, nums[j] - nums[i]);
            }
        }
        return answer == 0? - 1 : answer;
    }
};