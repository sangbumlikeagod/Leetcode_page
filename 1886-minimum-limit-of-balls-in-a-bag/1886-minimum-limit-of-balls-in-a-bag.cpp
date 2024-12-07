class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 0;
        for (int num : nums)
        {
            r = max(r, num);
        }
        while (l < r)
        {
            int m = (l + r) / 2;
            int tmp = 0;
            for (int num : nums)
            {
                if (num > m)
                {
                    tmp +=  (num / m + (num % m != 0)) - 1;
                }
            } 
            if (tmp <= maxOperations)
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