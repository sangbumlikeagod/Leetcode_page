class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> timeInts;
        for (string time : timePoints)
        {
            int timeInt = ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + (time[3] - '0') * 10 + (time[4] - '0');
            timeInts.push_back(timeInt);
        }
        sort(timeInts.begin(), timeInts.end());
        timeInts.push_back(timeInts[0] + 24 * 60);
        int answer = 24 * 60;

        for (int k = 1; k < timeInts.size(); k++)
        {
            answer = min(answer, timeInts[k] - timeInts[k - 1]);
        }
        return answer;
    }
};