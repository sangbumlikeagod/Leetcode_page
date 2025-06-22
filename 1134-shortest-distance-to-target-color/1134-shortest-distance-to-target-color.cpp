class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();

        vector<vector<int>> dpL(n + 1, vector<int>(3, -1));
        vector<vector<int>> dpR(n + 1, vector<int>(3, -1));
        dpL[0][colors[0] - 1] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (dpL[i - 1][j] == -1) continue;
                dpL[i][j] = dpL[i - 1][j] + 1; 
            }
            dpL[i][colors[i] - 1] = 0;
        }
        dpR[n - 1][colors[n - 1] - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < 3; j++)
            {
                if (dpR[i + 1][j] == -1) continue;
                dpR[i][j] = dpR[i + 1][j] + 1; 
            }
            dpR[i][colors[i] - 1] = 0;
        }
        vector<int> answer;
        for (vector<int>& query : queries)
        {
            if (dpL[query[0]][query[1] - 1] == -1 && dpR[query[0]][query[1] - 1] == -1)
            {
                answer.push_back(-1);
            }
            else if (dpL[query[0]][query[1] - 1] == -1)
            {
                answer.push_back(dpR[query[0]][query[1] - 1]);
            }
            else if (dpR[query[0]][query[1] - 1] == -1)
            {
                answer.push_back(dpL[query[0]][query[1] - 1]);
            }
            else 
            {
                answer.push_back(min(dpL[query[0]][query[1] - 1], dpR[query[0]][query[1] - 1]));
            }
        }
        return answer;

    }
};