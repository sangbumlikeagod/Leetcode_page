class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> nums_occurence(n + 1, 0);
        for (vector<int>& query : queries)
        {
            nums_occurence[query[0]]++;
            nums_occurence[query[1] + 1]--;
        }

        int maxDecrease = 0;
        for (int i = 0; i < n; i ++)
        {
            maxDecrease += nums_occurence[i];
            if (nums[i] > maxDecrease)
            {
                return false;
            }
        }
        return true;
    }
};