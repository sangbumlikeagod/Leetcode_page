class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int state = 0, answer = 0;

        int n = nums.size();
        for (int i = 1 ; i < n; i++)
        {
            // 올라가는중이었는데 내려간다면
            if (nums[i] < nums[i - 1] && state == 1)
            {
                answer++;
                state = 2;
            }
            if (nums[i] > nums[i - 1] && state == 2)
            {
                answer++;
                state = 1;
            }

            if (nums[i] < nums[i - 1])
            {
                state = 2;
            }
            else if (nums[i] > nums[i - 1])
            {
                state = 1;
            }
        }
        return answer;
    }
};