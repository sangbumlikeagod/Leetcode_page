class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> queries {};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    queries.push_back(vector<int> {i, j});
                }
            }
        }
        for (vector<int>& query : queries)
        {
            for (int k1 = 0; k1 < m; k1++)
            {
                matrix[k1][query[1]] = 0;
            }
            for (int k2 = 0; k2 < n; k2++)
            {
                matrix[query[0]][k2] = 0;
            }
        }
    }
};