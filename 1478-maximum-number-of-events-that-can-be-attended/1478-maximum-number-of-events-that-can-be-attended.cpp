class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size(), answer = 0;
        int maxx = 0;
        for (int i = 0; i < n; i++)
        {
            maxx = max(maxx, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<int>> q;
        
        sort(events.begin(), events.end());
        for (int i = 1, j = 0; i <= maxx; i++)
        {
            while (j < n && events[j][0] <= i)
            {
                q.push(events[j][1]);
                j++;
            }
            while(q.empty() == false && q.top() < i)
            {
                 q.pop();   
            }
            if (q.empty() == false)
            {
                q.pop(); answer++;
            }
        }
        return answer;
    }
};