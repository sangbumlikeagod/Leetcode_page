class Solution
{
    set<int, int> mapp;

public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int answer = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int tmp = i + 1;
            tmp -= mapp.end() - mapp.upper_bound(arr[i]);
            mapp[]
        }
    }
};