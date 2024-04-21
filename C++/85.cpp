class Solution
{
    int copyMatrix[201][201];

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < rowNum; i++)
        {
            for (int j = 0; j < colNum; j++)
            {
                if (matrix[i][j] == '1')
                {
                    copyMatrix[i][j] = 1;
                }
                else
                {
                    copyMatrix[i][j] = 0;
                                }
            }
        }
        for (int i = 0; i < rowNum; i++)
        {
            if (i != 0)
            {
                for (int j = 0; j < colNum; j++)
                {
                    if (copyMatrix[i][j] == 1)
                    {
                        copyMatrix[i][j] += copyMatrix[i - 1][j];
                    }
                }
            }

            // for (int i = 0; i < rowNum; i++)
            // {
            //     for (int j = 0; j < colNum; j++)
            //     {
            //         cout << copyMatrix[i][j] << '\t';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n' << '\n';

            for (int possibleKan = 1; possibleKan <= i + 1; possibleKan++)
            {
                int tmp = 0;
                for (int j = 0; j < colNum; j++)
                {
                    if (copyMatrix[i][j] >= possibleKan)
                    {
                        tmp += possibleKan;
                    }
                    else
                    {
                        ans = max(ans, tmp);
                        tmp = 0;
                    }
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};