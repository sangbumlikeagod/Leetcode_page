class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int prefix = 0;
        long long answer = 0; 
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix += (nums[i] % modulo) == k;
            answer += cnt[(prefix - k + modulo) % modulo];
            cnt[prefix % modulo]++;
        }
        return answer;
    }
};