class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int idx = nums.size() - 1;
        int answer = 0;
        while (idx >= 0)
        {
            int startValue = nums[idx--];
            while (idx >= 0 && nums[idx] == startValue) idx--;
            if (startValue == k) 
            {
                if (idx == -1)
                {
                    break; 
                }
                else
                {
                    return -1;
                }
            }
            else if (startValue < k)
            {
                return -1;
            }
            answer++;
        }
        return answer;
    }
};