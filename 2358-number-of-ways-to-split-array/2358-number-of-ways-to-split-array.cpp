class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sSum = 0;
        int answer = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sSum += nums[i];
        }
        long long tmp = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            tmp += nums[i];
            if (tmp >= sSum - tmp)
            {
                answer++;
            }
        }
        return answer;
    }
};