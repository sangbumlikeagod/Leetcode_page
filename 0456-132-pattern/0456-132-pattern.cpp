class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sSize = nums.size();
        if (sSize < 2) return false;
        vector<int> stacks;
        int last = INT_MIN;
        for (int i = sSize - 1; i >= 0; i--)
        {
            if (stacks.empty())
            {
                stacks.push_back(nums[i]);
            }
            else
            {
                if (stacks.back() <= nums[i])
                {
                    while(stacks.empty() == false && stacks.back() <= nums[i])
                    {
                        if (stacks.back() != nums[i])
                        {
                            last = stacks.back();
                        }
                        stacks.pop_back();
                    }
                }
                else
                {
                    if (last > nums[i])
                        return true;
                }
                stacks.push_back(nums[i]);

            }
        }
        return false;
    }
};