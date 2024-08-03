class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        int indexes[1001]{0};
        for (int ar : arr)
        {
            indexes[ar]++;
        }
        for (int tar : target)
        {
            if (!indexes[tar])
                return false;

            indexes[tar]--;
        }
        return true;
    }
};