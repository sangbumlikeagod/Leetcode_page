class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int ses = 0;
        for (vector<int>& arg : shift)
        {
            if (arg[0] == 0)
            {
                ses -= arg[1];
            }
            else
            {
                ses += arg[1];
            }

            if (ses < 0)
            {
                ses %= s.length() * -1; 
                while (ses < 0)
                {
                    ses += s.length();
                }
            }
            else
            {
                ses %= s.length();
            }
        }
        string answer = s;
        for (int i = 0; i < s.length(); i++)
        {
            answer[(i + ses) % s.length()] = s[i];
        }
        return answer;
    }
};