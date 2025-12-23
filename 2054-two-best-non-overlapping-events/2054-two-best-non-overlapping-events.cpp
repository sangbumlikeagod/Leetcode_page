class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>>  endSortEvent = events;
        sort(events.begin(), events.end());
        sort(endSortEvent.begin(), endSortEvent.end(), [](vector<int>& a, vector<int>& b){ return a[1] < b[1]; });

        int bByFar = 0;

        // 정렬해서 어느정도까지 정리하고 i번째 이벤트를 고른다고 했을 때 그것보다 일찍끝나는 모든이벤트들 중 가장 큰 값만 가지고 있으면 되니까 
        int firstL = 0, secondL = 0;
        int answer = 0;
        while (firstL < events.size())
        {
            
            while (secondL < events.size() && endSortEvent[secondL][1] < events[firstL][0])
            {
                bByFar = max(bByFar, endSortEvent[secondL][2]);
                secondL++;
            }
            // cout << firstL << ' ' << secondL << ' ' << bByFar << '\n';
            answer = max(answer, bByFar + events[firstL][2]);
            firstL++;
        }
        return answer;
        
    }
};