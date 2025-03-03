class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before;
        vector<int> same;
        vector<int> after;

        for (int num : nums)
        {
            if (num < pivot)
            {
                before.push_back(num);
            }
            else if (num == pivot)
            {
                same.push_back(num);
            }
            else
            {
                after.push_back(num);
            }
        }
        copy(same.begin(), same.end(), back_inserter(before));
        copy(after.begin(), after.end(), back_inserter(before));
        return before;
    }
};