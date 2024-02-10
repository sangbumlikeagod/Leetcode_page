class Solution
{
    int array[100];

public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        array[0] = nums[0];
        for (int i = 0; i < size; i++)
        {
            array[i] = nums[i];
        }

        for (int i = 0; i < size; i++)
        {
            if (i + 1 < size)
            {
                array[i + 1] = max(array[i + 1], array[i]);
            }
            if (i + 2 < size)
            {
                array[i + 2] = max(array[i + 2], array[i] + nums[i + 2]);
            }
        }

        return array[size - 1];
    }
};