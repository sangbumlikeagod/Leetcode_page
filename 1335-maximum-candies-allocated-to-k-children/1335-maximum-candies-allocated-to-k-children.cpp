class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        int l = 0, r = 10000000;
        while (l < r)
        {
            int m = (l + r) / 2 + (l + r) % 2;
            long long count = 0;
            for (int candy : candies)
            {
                count += candy / m;
            }
            if (count >= k)
            {
                l = m;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
};