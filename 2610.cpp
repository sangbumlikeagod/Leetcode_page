#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(vector<int> {nums[0]});
        int max_row = 0;
        int idx = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if ( nums[i] != nums[i - 1] )
            {
                idx = 0;
            }
            else 
            {
                idx++;
            }
            if ( max_row >= idx )
            {
                ans[idx].push_back(nums[i]);
            } 
            else 
            {
                ans.push_back(vector<int> {nums[i]});
                max_row = max(max_row, idx);
            }
        }
        return ans;
    }
};