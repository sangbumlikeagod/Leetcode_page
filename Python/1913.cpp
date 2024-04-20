class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return *(nums.end() - 1) * *(nums.end() - 2) - *(nums.begin()) * *(nums.begin() + 1);
    }
};