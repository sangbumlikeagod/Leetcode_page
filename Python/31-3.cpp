#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    pair<int, int> change(vector<int>& nums, int idx) {
        if (!idx) return make_pair(101, 0);
        int newIdx = idx - 1;
        pair<int, int> myResult = make_pair(101, idx);
        while (newIdx >= 0)
        {
            if (nums[idx] > nums[newIdx--])
            {
                myResult = make_pair(newIdx + 1, idx);
                break;
            }
        }
        pair<int, int> result = change(nums, idx - 1);
        return min(myResult, result);
    }
    void nextPermutation(vector<int>& nums) {
        pair<int, int> result = change(nums, nums.size() - 1);
        if (result.first == 101) {sort(nums.begin(), nums.end());}
        else
        {
            int tmp = nums[result.first];
            nums[result.first] = nums[result.second];
            nums[result.second] = tmp;
            sort(nums.begin() + result.first + 1, nums.end())

        }
        return; 
    }
};