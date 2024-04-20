class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        int idx = 0;
        int tmp;
        int size = nums.size();
        while (idx < size)
        {   
            tmp = nums[idx];
            if (!max1) 
            {
                max1 = tmp;
                idx++;
                continue;
            }

            if (tmp > max1) 
            {
                tmp = max1;
                max1 = nums[idx];
            }

            if (!max2)
            {
                max2 = tmp;
                idx++;
                continue;
            }
            if (tmp > max2) 
            {
                max2 = tmp;
            }

            idx++;
        }
        return (max1 - 1) * (max2 - 1);
    }
};