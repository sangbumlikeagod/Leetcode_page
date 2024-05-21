class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans = {};
        for (int arr = 0; arr < pow(2, size); arr++)
        {
            int degree = 1;
            int th = 0;
            vector<int> row = {};
            while (th < size)
            {
                if (arr & degree)
                {
                    row.push_back(nums[th]);
                }
                degree <<= 1;
                th++;
            }
            ans.push_back(row);
        }
        return ans;
    }
};