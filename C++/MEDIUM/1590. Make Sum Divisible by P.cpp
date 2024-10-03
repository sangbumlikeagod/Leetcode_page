class Solution
{
    unordered_map<int, vector<int>> prefixSumLeftover;
    vector<int> prefix{};

public:
    int minSubarray(vector<int> &nums, int p)
    {
        prefix.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        {
            int before = prefix[i];
            prefix.push_back((nums[i] + before) % p);
            prefixSumLeftover[(nums[i] + before) % p].push_back(i);
        }
        int totalGap = prefix[nums.size()];
        if (totalGap == 0)
        {
            return 0;
        }
        int answer = -1;

        for (int i = 0; i <= nums.size(); i++)
        {
            int wantedLeftover = (prefix[i] + totalGap) % p;

            auto p = upper_bound(prefixSumLeftover[wantedLeftover].begin(), prefixSumLeftover[wantedLeftover].end(), i - 1);
            if (p != prefixSumLeftover[wantedLeftover].end())
            {
                int def = (*p - i + 1);
                if ((answer == -1 || answer > def) && def != nums.size())
                {
                    answer = def;
                }
            }
        }
        return answer;
    }
};