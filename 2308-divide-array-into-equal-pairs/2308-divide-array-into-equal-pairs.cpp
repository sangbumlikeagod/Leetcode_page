class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> navv (501, 0);
        for (int num : nums)
        {
            navv[num]++;
        }

        for (int i = 0; i < 501; i++)
        {
            if (navv[i] % 2)
            {
                return false;
            }
        }
        return true;
    }
};