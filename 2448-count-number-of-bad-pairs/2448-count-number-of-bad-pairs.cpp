class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mapp;
        for (int i = 0; i < nums.size(); i++)
        {
            mapp[nums[i] - i]++;
        }
        long long llSize = nums.size();
        long long answer = (llSize * (llSize - 1)) / 2;
        for (auto con = mapp.begin(); con != mapp.end(); con++)
        {
            long long ac = con -> second;
            answer -= (ac * (ac - 1)) / 2;
        }
        return answer;
    }
};