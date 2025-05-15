class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int idx = 0;
        vector<string> answer;
        answer.push_back(words[idx]);
        for (int i = 1; i < words.size(); i++)
        {
            if (groups[i] != groups[idx])
            {
                answer.push_back(words[i]);
                idx = i;
            }
        }
        return answer;
    }
};