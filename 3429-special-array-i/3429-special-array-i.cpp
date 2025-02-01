class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool isEven = (nums[0] % 2);
        for (int i = 1; i < nums.size(); i++)
        {
            if (isEven)
            {
                if (nums[i] % 2)
                {
                    return false;
                }
            }
            else
            {
                if (nums[i] % 2 == 0)
                {
                    return false;
                }
            }
            isEven = !isEven;
        }
        return true;
    }
};