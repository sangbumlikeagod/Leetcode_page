class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maximumLeft = values[0] - 1;
        int answer = 0;
        for (int i = 1; i < values.size(); i++)
        {
            answer = max(answer, maximumLeft + values[i]);
            if (maximumLeft < values[i])
            {
                maximumLeft = values[i];
            }
            maximumLeft--;
        }
        return answer;
    }
};