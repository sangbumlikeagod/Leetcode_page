class Solution {
    vector<int> maxes;
public:
    int largestCombination(vector<int>& candidates) {
        maxes = vector<int> (30, 0);
        for (int candidate : candidates)
        {
            int idx = 0;
            while (candidate)
            {
                if (candidate & 1)
                {
                    maxes[idx]++;
                }
                candidate >>= 1;
                idx++;
            }
        }
        int answer = 0;
        for (int candidate : maxes)
        {
            answer = max(answer, candidate);
        }
        return answer;
    }
};