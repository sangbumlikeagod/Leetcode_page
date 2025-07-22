class Solution {

    void sub(int& l, vector<int>& memo, int& nowVal, vector<int>& nums) {
        l++;
        memo[nums[l]]--;
        nowVal -= nums[l];
    }
    void add(int& r, vector<int>& memo, int& nowVal, vector<int>& nums) {
        
        memo[nums[r]]++;
        nowVal += nums[r];
    }
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = -1, r = 0;
        // int memo[10001] = {0};
        vector<int> memo(10001);
        int n = nums.size();
        int nowVal = 0;
        int answer = 0;
        while (r < n)
            {
                add(r, memo, nowVal, nums);
                while (memo[nums[r]] > 1)
                {
                    sub(l, memo, nowVal, nums);
                }
                answer = max(answer, nowVal);
                r++;
            }
        return answer;
        
    }
};