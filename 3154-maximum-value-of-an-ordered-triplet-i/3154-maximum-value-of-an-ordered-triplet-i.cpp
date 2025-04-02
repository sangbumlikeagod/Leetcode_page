class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j])
                {
                    continue;
                }
                for (int k = j + 1; k < n; k++)
                {
                    answer = max((long long) (nums[i] - nums[j]) * nums[k], answer);
                }
            }
        }
        return answer;
    }
};