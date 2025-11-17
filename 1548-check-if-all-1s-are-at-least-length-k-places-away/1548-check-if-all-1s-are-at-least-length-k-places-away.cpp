class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int distance = 100001;
        for (int num : nums)
        {
            if (num == 0)
            {
                distance++;
            }
            else
            {
                if (distance < k)
                    return false;
                distance = 0;
            }
        }
        return true;

    }
};