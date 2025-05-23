class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        sort(nums.begin(), nums.end(), [k](int a, int b){
            return (a - (a ^ k)) < (b - (b ^ k));
        });
        // cout << (17 ^ k) << ' ' << (18 ^ k) << '\n';
        // for (int num : nums) {
        //     if ((num - (num ^ k)) > 0)
        //     {
        //         cout << num << ' ';
        //     }
        // }
        int n = nums.size();
        int idx = 0;
        while (idx < n)
        {
            // if (idx < n)
            // {
            //     cout << (nums[idx] ^ k) << ' ' << nums[idx] << '\n';
            // }

            if ((nums[idx] ^ k) > nums[idx])
            {
                // cout << idx << ' ';
                if (idx != n - 1 && ((nums[idx] ^ k) + (nums[idx + 1] ^ k)) > (nums[idx] + nums[idx + 1]))
                {
                    nums[idx] = (nums[idx] ^ k);
                    nums[idx + 1] = (nums[idx + 1] ^ k);
                    idx+=2;
                }
                else if (idx == n - 1)
                {
                    break;
                }
                else
                {
                    break;
                }
            }
            else break;
        }
        long long answer = 0;
        for (int num : nums)
        {
            answer += num;
        }
        return answer;
    }
};