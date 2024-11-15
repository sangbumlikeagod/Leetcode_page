class Solution {
    map<int, int> greatest;
public:
    bool primeSubOperation(vector<int>& nums) {
        greatest[0] = 1;
        vector<int> primes (1001, 0);
        for (int i = 2; i < 1001; i++)
        {
            if (primes[i])
                continue;
            int stackI = i + i;
            greatest[i] = 1;
            while (stackI < 1001)
            {
                primes[stackI] = 1;
                stackI += i;
            }
        }
        int lastIndex = nums.size() - 1;
        int diff = -1;
        while (lastIndex >= 0)
        {
            auto maybe = greatest.upper_bound(diff);
            if (maybe == greatest.end() || maybe -> first >= nums[lastIndex])
                return false;
            nums[lastIndex] -= maybe -> first;
            if (lastIndex)
            {
                diff = nums[lastIndex - 1] - nums[lastIndex];
            }
            lastIndex--;
        }
        return true;
    }
};