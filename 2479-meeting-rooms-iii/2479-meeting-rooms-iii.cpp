class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n);
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> seats_available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> seats_returnEvent;
        int seatsLeft = n;
        for (int i = 0; i < n; i++)
            {
                seats_available.push(i);
            }
        for (int i = 0; i < m; i++)
            {
                while(
                        seats_returnEvent.empty() == false && 
                         seats_returnEvent.top().first <= meetings[i][0]
                     )
                    {
                        seats_available.push(seats_returnEvent.top().second);
                        seats_returnEvent.pop();
                        seatsLeft++;
                    }
                
                 if (seatsLeft)
                 {
                     cnt[seats_available.top()]++;
                     seats_returnEvent.push({meetings[i][1], seats_available.top()});
                     seats_available.pop();
                     seatsLeft--;
                 }
                else
                 {
                    pair<long long, int> next = seats_returnEvent.top();
                    seats_returnEvent.pop();
                    seats_returnEvent.push({next.first + meetings[i][1] - meetings[i][0], next.second}); 
                     cnt[next.second]++;
                 }
            }
        int answer = 0;
        for (int i = 0; i < n; i++)
            {
                // cout << cnt[i] << ' '; 
                if (cnt[i] > cnt[answer])
                {
                    answer = i;
                }
            }
        return answer;
        
    }
};