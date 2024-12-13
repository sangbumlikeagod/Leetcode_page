class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long answer = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<int> visited(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            q.push(vector<int> {nums[i], i});
        }
        
        while (!q.empty())
        {
            if (visited[q.top()[1]])
            {
                q.pop();
                continue;
            }
            answer += q.top()[0];
            int tmp = q.top()[1];

            visited[tmp] = 1;
            if (tmp != 0)
            {
                visited[tmp - 1] = 1; 
            }
            if (tmp != nums.size() - 1)
            {
                visited[tmp + 1] = 1; 
            }

            q.pop();
        }

        return answer;
    }
};