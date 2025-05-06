class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> answer {};
        for (int num : nums)
        {
            answer.push_back(nums[num]);
        }
        return answer;
    }
};