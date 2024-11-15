class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int ans = nums.size();
        int ors = 0;
        vector<int> lololo (32, 0);
        vector<vector<int>> rororo(nums.size(), vector<int>{});
        while (r < nums.size())
        {
            int oR = r;
            // 얘를 먹을까 말까하는 순서여야함
            while (r < nums.size() && ors < k)
            {
                int ar = nums[r];
                int idx = 0;
                while (ar)
                {
                    if (ar & 1)
                    {
                        lololo[idx]++;
                        rororo[r].push_back(idx);
                    }
                    ar >>= 1;
                    idx++;
                }
                ors |= nums[r];
                r++;
            }
            if (oR == r)
            {
                int ar = nums[r];
                int idx = 0;
                while (ar)
                {
                    if (ar & 1)
                    {
                        lololo[idx]++;
                        rororo[r].push_back(idx);
                    }
                    ar >>= 1;
                    idx++;
                }
                ors |= nums[r];
                r++;
            }
            // cout << l << '\t' << r << '\t' << ors << '\n';
            while (l < r && ors >= k)
            {
                int orsCopy = ors;
                for (int idx : rororo[l])
                {
                    if (lololo[idx] == 1)
                    {
                        orsCopy ^= (1 << idx);
                    }
                }
                if (orsCopy < k || !orsCopy)
                    break; 
                // cout << l << ' ' << orsCopy << '\n';
                for (int idx : rororo[l])
                {
                    lololo[idx]--;
                    if (!lololo[idx])
                    {
                        ors ^= (1 << idx);
                    }
                }
                l++;
            }   
            ans = min(ans, r - l);
        }
        if (ans == nums.size() && ors < k)
        {
            return -1;
        }
        return ans;
    }
};