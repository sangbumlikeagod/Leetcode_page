#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int change(vector<int>& nums, int idx) {
        if (!idx) return 0;
        int newIdx = idx - 1;

        while (newIdx >= 0)
        {
            if (nums[idx] > nums[newIdx--])
            {
                int tmp = nums[idx];
                nums[idx] = nums[newIdx + 1];
                nums[newIdx + 1] = tmp;
                sort(nums[newIdx + 2], nums.end());
                return 1;
            }
        }
        int result = change(nums, idx - 1);
        if (!result) {return 0;}
        else {return 1}

    }
    void nextPermutation(vector<int>& nums) {
        int result = change(nums, nums.size() - 1);
        if (!result) sort(nums.begin(), nums.end(), greater<int>());
        return;
    }
};