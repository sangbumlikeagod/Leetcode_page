class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int answer = nums.size() + 1;
        long long prefixSum = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> queue; 
        queue.push({0, -1});
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            while(!queue.empty() && prefixSum - queue.top().first >= k)
            {
                answer = min(i - queue.top().second, answer);
                queue.pop();
            }
            queue.push({prefixSum, i});
        }
        return answer == nums.size() + 1 ? -1 : answer;
    }
};