class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxx = pow(2, n);
        int maxv = 0;
        for (int num : nums)
            {
                maxv |= num;
            }

        int answer = 0;
        for (int i = 1; i < maxx; i++)
            {
                int tmp = 0;
                for (int k = 0, j = 1; j < pow(2, n); j *= 2, k++)
                    {
                        if (i & j)
                        {
                            tmp |= nums[k];
                        }
                    }
                if (tmp == maxv)
                {
                    answer++;
                }
            }
        return answer;
    }
};