class Solution
{
    map<int, int> handMap;

public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int size = hand.size();
        if (groupSize == 1)
        {
            return true;
        }
        if (size % groupSize)
        {
            return false;
        }

        for (int index = 0; index < size; index++)
        {
            handMap[hand[index]]++;
        }

        int total = size / groupSize;
        for (int index = 0; index < total; index++)
        {
            vector<int> littleGroup{};
            map<int, int>::iterator start = handMap.begin();
            for (int idx = 0; idx < groupSize; idx++)
            {
                if (start == handMap.end())
                {
                    break;
                }
                int stat = start->first;
                if (!littleGroup.empty() && littleGroup[littleGroup.size() - 1] != stat - 1)
                {
                    return false;
                }
                littleGroup.push_back(stat);

                start->second--;
                if (!handMap[stat])
                {
                    handMap.erase(stat);
                }
                start++;
            }
            if (groupSize != littleGroup.size())
            {
                return false;
            }
        }
        return true;
    }
};