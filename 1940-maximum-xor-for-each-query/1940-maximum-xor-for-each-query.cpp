class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorS = 0;
        for (int num : nums)
        {
            xorS ^= num;
        }
        vector<int> answer;
        int maxNum = pow(2, maximumBit) - 1;
        while (!nums.empty())
        {
            int ans = 0;
            int idx = 0;
            int idxBit = 1;
            answer.push_back(xorS ^ maxNum);
            xorS ^= nums.back();
            nums.pop_back();
        }
        return answer;
    }
};