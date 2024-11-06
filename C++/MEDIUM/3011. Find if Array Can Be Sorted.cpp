class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        vector<int> vals;
        vector<vector<int>> numSort;
        int idx = 0;
        for (int num : nums)
        {
            int nnum = num;
            int val = 0;
            while (nnum)
            {
                if (nnum & 1)
                {
                    val++;
                }
                nnum >>= 1;
            }
            vals.emplace_back(val);
            numSort.push_back({num, idx++});
        }
        sort(numSort.begin(), numSort.end());
        for (int i = 0; i < idx; i++)
        {
            int ii = i;
            int j = numSort[i][1];
            if (j < ii)
            {
                swap(ii, j);
            }
            for (; ii < j; ii++)
            {
                if (vals[ii] != vals[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};