class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int val = lower_bound(nums.begin(), nums.end(), lower) - nums.begin();
        val = 0;
        long long answer = 0;
        while(val < nums.size())
        {
            int tmo = (upper_bound(nums.begin(), nums.end(), upper - nums[val]) - nums.begin());
            tmo -= max((upper_bound(nums.begin(), nums.end(), lower - nums[val] - 1) - nums.begin()), (long) val + 1);
            if (tmo > 0)
            {
                answer += tmo;
            }
            val++;
        }
        return answer;
    }
};