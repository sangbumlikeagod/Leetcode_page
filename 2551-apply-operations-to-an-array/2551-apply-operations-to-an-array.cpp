class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> answer;
        int zero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ( i != nums.size() - 1 && nums[i] == nums[i + 1] )
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i])
            {
                answer.push_back(nums[i]);
            }
            else
            {
                zero++;
            }
        }
        for (int i = 0; i < zero; i++)
        {
            answer.push_back(0);
        }
        
        return answer;
    }
};