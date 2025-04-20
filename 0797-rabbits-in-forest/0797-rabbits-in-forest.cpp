class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int answer = 0;
        for (int ans : answers)
        {
            count[ans + 1]++;
        }
        for (auto arg = count.begin(); arg != count.end(); arg++)
        {
            answer += arg->first * ((arg->second / arg->first) + ((arg->second % arg->first) != 0));
        }
        return answer;
    }
};