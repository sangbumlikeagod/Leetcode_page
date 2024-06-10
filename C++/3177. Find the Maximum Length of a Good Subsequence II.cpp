class Solution
{
    int dp[5001][51] = {0};
    int maxLength[51] = {0};
    unordered_map<int, int> indexNum;

public:
    int maximumLength(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int index = 0; index < nums.size(); index++)
        {
            int indexPast = indexNum.find(nums[index]) == indexNum.end() ? index : indexNum[nums[index]];
            for (int kIndex = k; kIndex >= 0; kIndex--)
            {
                int nonKEnd = kIndex ? maxLength[kIndex - 1] : 0;
                int KEnd = indexPast == index ? 0 : dp[indexPast][kIndex];
                dp[index][kIndex] = max(nonKEnd + 1, KEnd + 1);
                maxLength[kIndex] = max(maxLength[kIndex], dp[index][kIndex]);
            }
            indexNum[nums[index]] = index;
        }

        for (int kIndex = 0; kIndex <= k; kIndex++)
        {
            ans = max(ans, maxLength[kIndex]);
        }
        return ans;
    }
};