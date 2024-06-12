class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3] = {0};
        for (int num : nums)
        {
            color[num]++;
        }
        for (int index = 0; index < nums.size(); index++)
        {
            if (color[0])
            {
                color[0]--;
                nums[index] = 0;
            }
            else if (color[1])
            {
                color[1]--;
                nums[index] = 1;
            }
            else
            {
                color[2]--;
                nums[index] = 2;
            }
        }
    }
};