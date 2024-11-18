class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        queue<int> q;
        vector<int> answer(nums.size() - k + 1, 0);
        if (k == 1)
        {
            return nums;
        }
        for (int i = 1; i < k; i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                q.push(i);
            }
        }

        for (int i = k - 1; i < nums.size(); i++)
        {
            int tmp = 0;
            if (nums[i] != nums[i - 1] + 1)
            {
                if (i != k - 1)
                    q.push(i);
                tmp = -1;
            }
            else
            {
                if (q.empty())
                {
                    tmp = nums[i];
                }
                else
                {
                    tmp = -1;
                }
            }
            answer[i - k + 1] = tmp;
            if (q.front() == i - k + 2)
            {
                q.pop();
            }
        }
        return answer;
    }
};