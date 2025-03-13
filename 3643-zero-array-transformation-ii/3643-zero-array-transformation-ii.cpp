class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int current = 0;
        map<int, int> arranges;
        int idx = 0;


        for (int i = 0; i < nums.size(); i++)
        {
            int memo = -1;
            // cout << current << '\n';
            for (auto arg = arranges.begin(); arg != arranges.end(); arg++)
            {
                if (arranges.find(memo) != arranges.end())
                {
                    arranges.erase(memo);
                }
                if (arg -> first <= i)
                {
                    current += arg -> second;
                    memo = arg -> first;
                    // cout << '\t' << arg-> first << '\t' << arg -> second << '\n';
                }
            }
            if (arranges.find(memo) != arranges.end())
            {
                arranges.erase(memo);
            }
            // cout << i << '\n';
            while (idx < queries.size() && current < nums[i])
            {
                vector<int>& query = queries[idx++];
                if (query[0] <= i)
                {
                    current += query[2];
                }
                else
                {
                    // cout << '\t' << '\t'<< query[0] << '\t' << query[2] << '\n'; 
                    arranges[query[0]] += query[2];
                }
                if (query[1] < i)
                {
                    current -= query[2];
                }
                else
                {
                    // cout << '\t' << '\t'<< query[1] + 1 << '\t' << query[2] * -1 << '\n'; 
                    arranges[query[1] + 1] -= query[2];
                }
                if (current >= nums[i]) break;
            }
            // cout << i << ' ' << current  << ' ' << idx << '\n';
            if (nums[i] > current)
            {
                return -1;
            }
        }
        return idx;
    }
};