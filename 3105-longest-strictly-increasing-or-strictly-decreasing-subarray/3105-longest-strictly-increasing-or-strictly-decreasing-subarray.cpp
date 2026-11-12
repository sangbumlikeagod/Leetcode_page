class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 1;
        }

        int before, answer = 0, length = 1;
        int type = -1;
        if (nums[0] < nums[1])
        {
            before = nums[0] - 1;
            type = 1;
        }
        else if (nums[0] == nums[1])
        {
            before = nums[0];
            type = 2;
        }
        else
        {
            before = nums[0] + 1;
            // 줄어드는중 
            type = 3;
        }
        
        for (int i = 1; i < nums.size(); i++)
        {
            int num = nums[i];
            if (num > before)
            {
                if (type != 1)
                {
                    type = 1;
                    length = 2;
                }
                else
                {
                    length++;
                }
            }
            else if (num < before)
            {
                // 줄어드는중
                if (type != 3)
                {
                    type = 3;
                    length = 2;
                }
                else
                {
                    length++;
                }
            }
            else
            {
                type = 2;
                length = 1;
            }
            before = num;
            answer = max(answer, length);
        }
        return answer;
    }
};