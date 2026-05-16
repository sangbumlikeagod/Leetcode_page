class Solution {
private:
    // int minVal = 5001;
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

        vector<int> uniqueNums;
        vector<int> visited(10001, 0);
        for (int num : nums)
        {
            if (visited[num + 5000] == 0)
            {
                visited[num + 5000] = 1;
                uniqueNums.push_back(num);
            }
        }
        if (uniqueNums.size() == 1) return uniqueNums[0];

        int idx = newBinarySearch(0, uniqueNums.size() - 1, uniqueNums);
        // cout << idx;
        if (idx == 0 && uniqueNums[0] < uniqueNums[1])
        {
            return uniqueNums[idx];
        }
        return idx == uniqueNums.size() - 1 ? uniqueNums[0] : uniqueNums[idx + 1];
    }
};