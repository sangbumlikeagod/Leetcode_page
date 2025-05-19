class Solution {
public:
    string triangleType(vector<int>& nums) {
        {
            if (
                nums[0] + nums[1] <= nums[2] ||
                nums[2] + nums[1] <= nums[0] ||
                nums[0] + nums[2] <= nums[1] 
            )
            {
                return "none";
            }
            if (nums[0] == nums[1])
            {
                if (nums[0] == nums[2])
                {
                    return "equilateral";
                }
                return "isosceles";
            }
            if (nums[0] == nums[2])
            {
                return "isosceles";
            }
            if (nums[1] == nums[2])
            {
                return "isosceles";
            }
            return "scalene";
        }   
    }
};