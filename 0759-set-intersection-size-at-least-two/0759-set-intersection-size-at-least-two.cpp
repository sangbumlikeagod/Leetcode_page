class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] != b[0])
            {
                return a[0] < b[0];
            }
            else
            {
                return a[1] > b[1];
            }
        });
        int n = intervals.size();
        vector<int> left(n, 2);

        int last = n;
        int answer = 0;
        while (--last >= 0)
        {
            int s = intervals[last][0];
            int dots = left[last];
            for (int i = s; i < s + dots; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (left[j] && i <= intervals[j][1])
                    {
                        left[j]--;
                    }
                }
                answer++;
            }
        }
        return answer;

    }
};