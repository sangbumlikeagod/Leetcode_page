class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        const int MODULO = 1000000007;
        vector<int> prefixSum(nums.size(), 0);
        vector<int> subArrayList{};
        prefixSum[0] = nums[0];
        for (int nI = 1; nI < nums.size(); nI++)
        {
            prefixSum[nI] = nums[nI] + prefixSum[nI - 1];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j)
                {
                    subArrayList.push_back(prefixSum[i] - prefixSum[j - 1]);
                }
                else
                {
                    subArrayList.push_back(prefixSum[i]);
                }
            }
        }
        sort(subArrayList.begin(), subArrayList.end());
        int answer = 0;
        for (; left <= right; left++)
        {
            answer += subArrayList[left - 1];
            answer %= MODULO;
        }
        return answer;
    }
};