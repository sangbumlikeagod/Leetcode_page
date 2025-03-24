class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<int> meetSerial {};
        for (vector<int>& meeting : meetings)
        {
            meetSerial.push_back(meeting[0]);
            meetSerial.push_back((meeting[1] + 1) * -1);
        }
        sort(meetSerial.begin(), meetSerial.end(), [](int a, int b){
            if (a < 0) a *=-1;
            if (b < 0) b *=-1;
            return a < b;
        });  
        int time = 1;
        int answer = 0;
        int count = 0;
        for (int meet : meetSerial)
        {
            if (meet > 0)
            {
                if (count == 0)
                {
                    answer += meet - time;
                }
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    time = meet * -1;
                }
            }
        }
        answer += days - time + 1;
        return answer;
    }
};