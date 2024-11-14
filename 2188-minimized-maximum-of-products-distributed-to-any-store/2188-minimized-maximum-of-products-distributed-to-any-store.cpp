class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long total = 0;
        int maxN = 0;
        for (int type : quantities)
        {
            total += type;
            maxN = max(maxN, type);
        }
        if (total <= n)
        {
            return 1;
        }

        int minN = 1;
        while (minN < maxN)
        {
            int mid = (minN + maxN) / 2;
            int tmp = 0;
            for (int quantity : quantities)
            {
                tmp += (quantity) / mid + ((quantity) % mid != 0);
            }
            if (tmp > n)
            {
                minN = mid + 1;
            }
            else
            {
                maxN = mid;
            }
        }
        return maxN;
    }
};