class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected = heights;
        int size = heights.size();
        int ans = 0;
        sort(expected.begin(), expected.end());
        for (int index = 0; index < size; index++)
        {
            if (expected[index] != heights[index])
            {
                ans++;
            }
        }
        return ans;
    }
};