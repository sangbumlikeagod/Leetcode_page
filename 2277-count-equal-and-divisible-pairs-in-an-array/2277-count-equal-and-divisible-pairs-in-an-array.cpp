class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int answer = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (nums[i] != nums[j]) continue;
                if ((i * j) % k == 0)
                {
                    answer++;
                }
            }
        }
        return answer;
    }
};