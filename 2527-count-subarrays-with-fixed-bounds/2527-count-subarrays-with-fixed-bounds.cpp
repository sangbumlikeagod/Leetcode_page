class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> miniMono;
        vector<int> maxMono;
        vector<int> totalMono;
        long long answer = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                maxMono.clear();
                miniMono.clear();
                totalMono.clear();
            }
            else
            {
                if (nums[i] == minK)
                {
                    miniMono.clear();
                }
                if (nums[i] == maxK)
                {
                    maxMono.clear();
                }
                maxMono.push_back(nums[i]);
                miniMono.push_back(nums[i]);
                totalMono.push_back(nums[i]);
                if (maxMono[0] == maxK && miniMono[0] == minK)
                {
                    answer += (totalMono.size() -  max(maxMono.size() , miniMono.size())) + 1;
                }
            }
        }
        return answer;
    }
};