class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> frequency(202, 0);
        for (int num : nums)
        {
            frequency[num + 100]++;
        }
        sort(nums.begin(), nums.end(), [&frequency](int a, int b)
             { return frequency[a + 100] != frequency[b + 100] ? frequency[a + 100] < frequency[b + 100] : a > b; });
        return nums;
    }
};