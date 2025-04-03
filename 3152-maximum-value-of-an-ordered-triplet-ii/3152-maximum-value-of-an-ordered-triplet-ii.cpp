class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();
        long long bigg = 0;
        long long bigg_difference = 0;
        for (int i = 0 ; i < n; i++)
        {
            answer = max(answer,bigg_difference * nums[i]);
            if (nums[i] > bigg)
            {
                bigg = nums[i];
            }
            else
            {
                bigg_difference = max(bigg_difference, bigg - nums[i]);
            }
        }
        return answer;
    }
};