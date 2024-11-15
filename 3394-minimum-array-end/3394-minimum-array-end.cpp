class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> nums (65, 0);
        int idx = 64;
        n--;
        while (x)
        {
            nums[idx] = x & 1;
            x >>= 1;
            idx--;
        }
        idx = 64;
        while (n)
        {
            while (nums[idx])
            {
                idx--;
            }
            nums[idx] = n & 1;
            n >>= 1;
            idx--;
        }
        long long answer = 0;
        for (int i = 0; i <= 64; i++)
        {
            answer |= nums[i];
            answer <<= 1;
        }
        return answer >> 1;
    }
};