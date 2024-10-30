class Solution
{
    vector<int> l;
    vector<int> r;

public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        l = vector<int>(n, 1);
        r = vector<int>(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j])
                {
                    l[j] = max(l[j], l[i] + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] < nums[j])
                {
                    r[j] = max(r[j], r[i] + 1);
                }
            }
        }
        int answer = n;
        for (int i = 1; i < n - 1; i++)
        {
            if (l[i] == 1 || r[i] == 1)
                continue;
            answer = min(answer, n - (l[i] + r[i] - 1));
        }
        return answer;
    }
};