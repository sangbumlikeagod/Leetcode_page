class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        vector<int> prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int countOne = prefixSum[nums.size() - 1];
        int answer = countOne;
        for (int eI = 0; eI < nums.size(); eI++)
        {
            int iI = eI - countOne;
            if (iI < -1)
            {
                iI += nums.size();
            }
            if (eI < iI)
            {
                answer = min(answer, countOne - (prefixSum[eI] + prefixSum[nums.size() - 1] - prefixSum[iI]));
            }
            else
            {
                if (iI == -1)
                {
                    answer = min(answer, countOne - prefixSum[eI]);
                }
                else
                {
                    answer = min(answer, countOne - (prefixSum[eI] - prefixSum[iI]));
                }
            }
        }
        return answer;
    }
};