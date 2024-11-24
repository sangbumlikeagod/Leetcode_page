class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long positiveSum = 0, negativeSum = 0;
        int minPositive = INT_MAX, maxNegative = INT_MIN;
        int negetiveCount = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] < 0)
                {
                    negetiveCount++;
                    negativeSum += matrix[i][j];
                    maxNegative = max(maxNegative, matrix[i][j]);
                }
                else
                {
                    positiveSum += matrix[i][j];
                    minPositive = min(minPositive, matrix[i][j]);
                }
            }
        }
        if (negetiveCount % 2)
        {
            positiveSum -= minPositive;
            negativeSum -= maxNegative;
            return positiveSum - negativeSum + abs(minPositive + maxNegative);
        }
        else
        {
            return positiveSum - negativeSum;
        }
    }
};