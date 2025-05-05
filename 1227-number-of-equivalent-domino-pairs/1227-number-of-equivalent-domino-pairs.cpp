class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> cnt;
        int answer = 0;
        for (vector<int>& domino : dominoes)
        {
            int st = domino[0] * 10 + domino[1] , re = domino[1] * 10 + domino[0];
            if (re != st)
            {
                answer += cnt[st] + cnt[re];
            }
            else
            {
                answer += cnt[st];
            }
            cnt[st]++;
        }
        return answer;
    }
};