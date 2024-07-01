class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        if (arr.size() < 2)
            return false;
        int first = 0;
        int second = 1;
        int third = 2;

        while (third < arr.size())
        {
            if ((arr[first] * arr[second] * arr[third]) % 2)
            {
                return true;
            }
            first = second;
            second = third;
            third++;
        }
        return false;
    }
};