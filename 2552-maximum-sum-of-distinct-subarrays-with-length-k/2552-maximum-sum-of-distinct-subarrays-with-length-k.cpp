class Solution {
    unordered_map<int, int> ovrlap;
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0;
        long long answer = 0;
        long long tSum = 0;
        int ovrcnt = 0;
        bool isDistinct = true;
        while (r < k)
        {
            if (ovrlap.find(nums[r]) != ovrlap.end())
            {
                if (ovrlap[nums[r]] == 1)
                    ovrcnt++;
                isDistinct = false;
            }
            ovrlap[nums[r]]++;
            tSum += nums[r];
            r++;
        }
        answer = ovrcnt ? 0 : tSum;
        while (r < nums.size())
        {
            tSum -= nums[l];
            ovrlap[nums[l]]--;
            if (ovrlap[nums[l]] == 0)
            {
                ovrlap.erase(nums[l]);
            }
            else if (ovrlap[nums[l]] == 1)
            {
                ovrcnt--;
            } 
            if (ovrlap.find(nums[r]) != ovrlap.end())
            {
                if (ovrlap[nums[r]] == 1)
                    ovrcnt++;
            }
            ovrlap[nums[r]]++;
            tSum += nums[r];
            r++; l++;
            if (ovrcnt == 0)
            {
                answer = max(answer, tSum);
            }
        }
        return answer;
    }
};