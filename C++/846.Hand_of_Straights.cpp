class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int size = hand.size();
        if (size % groupSize)
        {
            return false;
        }
        sort(hand.begin(), hand.end());
    }
};