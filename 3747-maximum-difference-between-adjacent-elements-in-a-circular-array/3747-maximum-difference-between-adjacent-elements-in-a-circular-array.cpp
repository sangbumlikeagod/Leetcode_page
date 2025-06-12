class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int answer = abs(nums.back() - nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            answer = max(answer, abs(nums[i] - nums[i - 1]));
        } 
        return answer;
    }
};