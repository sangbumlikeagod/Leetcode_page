class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int Tsize = matrix.size();
        int Csize = matrix[0].size();
        vector<vector<int>> flips (Tsize * 2, vector<int>{});
        int answer = 0;
        for (int i = 0; i < Tsize; i++)
        {
            for (int j = 0; j < Csize; j++)
            {
                if (matrix[i][j] == 0)
                {
                    flips[i].push_back(j);
                }
                else
                {
                    flips[i + Tsize].push_back(j);
                }
            }
            if (flips[i].size() == 0 || flips[i + Tsize].size() == 0)
            {
                answer++;
            }
        }

        for (int i = 0; i < Tsize * 2; i++)
        {
            int tmp = 1;
            for (int j = 0; j < Tsize * 2; j++)
            {
                // cout << '\t' << i  << ' ' << j  << '\n';
                if ((i % Tsize) == (j % Tsize) || (flips[i].size() != flips[j].size()) )
                    continue;
                
                bool isSame = true;
                for (int k = 0; k < flips[i].size(); k++)
                {
                    // cout << flips[i][k] << ' ' << flips[j][k] << '\n';
                    if (flips[i][k] != flips[j][k])
                    {
                        isSame = false;
                        break;
                    }
                }
                if (!isSame)
                    continue;
                tmp++;
            }
            answer = max(answer, tmp);
        }
        return answer;

    }
};