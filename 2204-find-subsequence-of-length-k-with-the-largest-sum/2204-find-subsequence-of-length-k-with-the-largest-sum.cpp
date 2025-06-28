class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> pairs {};
        for (int i = 0; i < n; i++)
            {
                pairs.push_back({nums[i], i});
            }
        sort(pairs.begin(), pairs.end());
        vector<pair<int,int>> pairs_k(pairs.end() - k, pairs.end());
        sort(pairs_k.begin(), pairs_k.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second < b.second;
        });
        vector<int> answer {};
        for (int i = 0; i < k; i++)
            {
                answer.push_back(pairs_k[i].first);
            }
        return answer;
    }
};