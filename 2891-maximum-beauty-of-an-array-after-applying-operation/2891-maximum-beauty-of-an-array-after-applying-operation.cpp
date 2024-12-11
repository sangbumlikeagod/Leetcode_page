class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> idxQ (100002, 0);
        int sSize = nums.size();
        for (int i = 0; i < sSize; i++)
        {
            idxQ[nums[i]]++;
        }

        int answer = 0;
        int slideW = 0;
        for (int j = 0; j <= min(2 * k, 100000); j++)
        {
            slideW += idxQ[j];
        }
        answer = max(answer, slideW);

        for (int j = k; j <= 100000 - k; j++)
        {

            slideW -= idxQ[j - k];
            slideW += idxQ[j + k + 1];
            answer = max(answer, slideW);

        }
        return answer;
    }
};