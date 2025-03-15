class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 1000000000;
        while (l < r)
        {
            // int m = (l + r) / 2 + (l + r) % 2;
            int m = (l + r) / 2;
            // cout << l << ' ' <<  m << ' '  << r << '\n';
            int num = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] <= m) 
                {
                    num++;
                    i++;
                }
            }
            if (num >= k)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
};