class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int total = 0;
        int answer = 1;
        int l = 0, r = 0;
        while (r < nums.size())
        {
            while (total & nums[r])
            {
                total ^= nums[l++];
            }
            total |= nums[r++];
            answer = max(answer, r - l);
        }
        return answer;
    }
};