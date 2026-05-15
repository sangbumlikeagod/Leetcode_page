class Solution {
private:
    int newBinarySearch(int l, int r, vector<int>& nums)
    {

        while (l < r)
        {
            int base = nums[nums.size() - 1];
            int m = (l + r) / 2;
            if (nums[m] > nums[m + 1])
            {
                return m;
            }
            else if (nums[m] > base)
            {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return l;
    }
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int idx = newBinarySearch(0, nums.size() - 1, nums);
        // cout << idx;
        if (idx == 0 && nums[0] < nums[1])
        {
            return nums[idx];
        }
        return idx == nums.size() - 1 ? nums[0] : nums[idx + 1];
    }
};