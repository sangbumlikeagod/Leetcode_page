class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long answer = 0;
        int l = 0, r = 0, count = 0, size = nums.size();
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxVal = max(maxVal, nums[i]);
        }
        
        while (r <= size || (l < size && l < r))
        {
            if (r < size && count < k)
            {
                if (nums[r] == maxVal)
                {
                    count++;
                }
                r++;
            }
            else if (l < size)
            {
                // cout << l << ' ' << r << '\n';
                if (count >= k)
                {
                    answer += (size - r + 1);
                }
                if (nums[l] == maxVal)
                {
                    count--;
                }
                l++;
            }
            else
            {
                r++;
            }
        }
        return answer;
        
    }
};