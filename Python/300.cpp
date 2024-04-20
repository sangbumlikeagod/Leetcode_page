class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};

// 내 코드
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis (nums.size() + 1, 1);
        lis[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j]){
                     lis[j] = max(lis[i] + 1, lis[j]);
                } 
            }
            lis[nums.size()] = max(lis[i], lis[nums.size()]);
        }
    return lis[nums.size()];
    }
};
// 이진탐색 코드 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> tails(nums.size(), 0);
        int size = 0;

        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if (i == size) ++size;
        }
        return size;
    }
};

