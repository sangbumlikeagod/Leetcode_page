class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

        q.push({0, -1});
        long long prefixSum = 0;
        int answer = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            while (!q.empty() && prefixSum - k >= q.top().first)
            {
                answer = min(answer,i - q.top().second);
                q.pop();
            }   
            q.push({prefixSum, i});
        }
        return answer == nums.size() + 1 ? -1 : answer;
    }
};