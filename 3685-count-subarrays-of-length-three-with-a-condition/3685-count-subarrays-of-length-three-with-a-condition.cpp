class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int answer = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i + 1] == 2 *(nums[i] + nums[i + 2]))
            {
                answer++;
            }
        }
        return answer;
    }
};