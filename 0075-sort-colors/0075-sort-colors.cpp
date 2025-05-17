class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int num : nums)
        {
            if (num == 0)
            {
                zero++;
            }
            else if (num == 1)
            {
                one++;
            }
            else {
                two++;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (zero)
            {
                nums[i] = 0;
                zero--;
            }
            else if (one)
            {
                nums[i] = 1;
                one--;
            }
            else if (two)
            {
                nums[i] = 2;
                two--;
            }
        }
    }
};