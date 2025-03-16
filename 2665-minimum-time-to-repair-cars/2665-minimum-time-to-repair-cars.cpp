class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 100000000000000;
        while (l < r)
        {
            long long m = (l + r) / 2;
            int left = cars;
            for (int rank : ranks)
            {
                left -= (int) sqrt(m / rank);
                if (left <= 0) break;
            }
            if (left <= 0)
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