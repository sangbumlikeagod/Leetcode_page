class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> answer{0, 0};
        vector<vector<int>> integrated{};
        int k = nums.size();
        int maxCount = k;
        vector<int> windowCount(k, 0);

        for (int i = 0; i < k; i++)
        {
            for (int a : nums[i])
            {
                integrated.push_back(vector<int>{a, i});
            }
        }

        sort(integrated.begin(), integrated.end());

        int s = 0;
        int e = 0;
        int tLength = integrated.size();

        while (maxCount)
        {
            if (!windowCount[integrated[e][1]])
            {
                maxCount--;
            }
            windowCount[integrated[e][1]]++;
            e++;
        }
        while (windowCount[integrated[s][1]] > 1)
        {
            windowCount[integrated[s][1]]--;
            s++;
        }
        answer[0] = integrated[s][0];
        answer[1] = integrated[e - 1][0];

        while (e < tLength)
        {
            windowCount[integrated[e][1]]++;
            while (windowCount[integrated[s][1]] > 1)
            {
                windowCount[integrated[s][1]]--;
                s++;
            }
            if (integrated[e][0] - integrated[s][0] < answer[1] - answer[0])
            {
                answer[0] = integrated[s][0];
                answer[1] = integrated[e][0];
            }
            e++;
        }

        return answer;
    }
};