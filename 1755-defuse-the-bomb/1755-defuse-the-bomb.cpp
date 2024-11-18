class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> answer (code.size(), 0);
        if (k == 0) return answer;
        for (int i = 0; i < code.size(); i++)
        {
            if (k > 0)
            {  
                for (int j = i + 1; j <= i + k; j++)
                {
                    int next = j >= code.size() ? j - code.size() : j;
                    answer[i] += code[next];
                }
            }
            else if (k < 0)
            {
                for (int j = i + k; j < i; j++)
                {
                    int next = j >= 0 ? j : j + code.size();
                    answer[i] += code[next];
                }
            }
        }
        return answer;
    }
};