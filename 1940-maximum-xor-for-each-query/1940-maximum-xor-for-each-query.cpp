class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorS = 0;
        for (int num : nums)
        {
            xorS ^= num;
        }
        vector<int> answer;
        int maxNum = pow(2, maximumBit);
        while (!nums.empty())
        {
            int ans = 0;
            int idx = 0;
            int idxBit = 1;
            while (maximumBit > idx)
            {
                if ((idxBit & xorS) == 0)
                {
                    ans += idxBit;
                }
                idxBit <<= 1;
                idx++;
            }
            answer.push_back(ans);
            xorS ^= nums.back();
            nums.pop_back();
        }
        return answer;
    }
};