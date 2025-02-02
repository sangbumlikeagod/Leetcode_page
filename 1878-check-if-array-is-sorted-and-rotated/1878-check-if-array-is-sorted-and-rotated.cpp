class Solution {
public:
    bool check(vector<int>& nums) {
        int chance = 1;
        int before = -1;
        int highest = INT_MAX;
        for (int num : nums)
        {
            if (before > num)
            {
                if (chance == 0)
                {
                    return false;
                }
                chance--;
            }
            if (chance)
            {
                highest = min(num, highest);
            }
            else
            {
                if (highest < num)
                {
                    return false;
                }
            }
            before = num;
        }
        return true;
    }
};