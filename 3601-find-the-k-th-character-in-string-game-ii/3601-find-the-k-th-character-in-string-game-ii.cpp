class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long d = 1; int d_c = 0;
        while (d < k)
            {
                d *= 2; d_c++;
            }

        int ans = 0;

        while (k > 1)
            {
                if (k > d)
                {
                    k -= d;
                    ans = (ans + operations[d_c]) % 26;
                }
                d /= 2; d_c--;
            }
        return 'a' + ans;
    }
};