class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> answer;

        vector<vector<int>> arg1 (words1.size(), vector<int> (26, 0));
        vector<int> arg2(26, 0);
        
        int index = 0;
        for (string& word1 : words1)
        {
            for (char c : word1)
            {
                arg1[index][c - 'a']++;
            }
            index++;
        }
        index = 0;
        for (string& word2 : words2)
        {
            vector<int> tmp (26, 0);
            for (char c : word2)
            {
                tmp[c - 'a']++;
            }
            index++;
            for (int i = 0; i < 26; i++)
            {
                arg2[i] = max(arg2[i], tmp[i]);
            }
        }

        for (int i = 0; i < words1.size(); i++)
        {
            bool flag = true;

            for (int k = 0; k < 26; k++)
            {
                if (arg2[k] && arg2[k] > arg1[i][k])
                {
                    flag = false; break;
                }
            }
            if (flag) answer.push_back(words1[i]);
        }
            
        return answer;
    }
};