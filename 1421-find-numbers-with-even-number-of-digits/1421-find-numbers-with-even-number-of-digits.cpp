class Solution {
public:
    int findNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz1 = upper_bound(nums.begin(), nums.end(), 99) - upper_bound(nums.begin(), nums.end(), 9);
        int sz2 = upper_bound(nums.begin(), nums.end(), 9999) - upper_bound(nums.begin(), nums.end(), 999);
        int sz3 = nums.end() - upper_bound(nums.begin(), nums.end(), 99999);
        return sz1 + sz2 + sz3;
    }
};