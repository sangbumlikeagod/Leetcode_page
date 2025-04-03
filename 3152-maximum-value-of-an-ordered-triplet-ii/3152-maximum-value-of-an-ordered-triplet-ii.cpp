class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();
        vector<int> stacck {nums[0]};

        // 이제까지의 최대값, 그때까지의 차의 최대값, 그리고 그거에대한 항상 곱
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