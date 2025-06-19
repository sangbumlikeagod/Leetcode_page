class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto n = nums.begin();
        int answer = 0;
        while (n != nums.end())
        {
            n = upper_bound(nums.begin(), nums.end(), (*n) + k);
            answer++;
        }
        return answer;
    }
};