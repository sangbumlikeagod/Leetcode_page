class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {

        vector<vector<vector<int>>> dp(books.size() + 1, vector<vector<int>>(shelfWidth + 1, vector<int>{1000001, 0}));
        dp[0][shelfWidth][0] = 0;
        int answer = 1000001;
        for (int i = 0; i < books.size(); i++)
        {
            for (int j = 0; j <= shelfWidth; j++)
            {
                if (dp[i][j][0] != 1000001)
                {
                    if (books[i][0] <= j)
                    {
                        int added = max(books[i][1] - dp[i][j][1], 0);
                        if (dp[i + 1][j - books[i][0]][0] > added + dp[i][j][0])
                        {
                            dp[i + 1][j - books[i][0]][0] = added + dp[i][j][0];
                            if (added)
                                dp[i + 1][j - books[i][0]][1] = books[i][1];
                            else
                            {
                                dp[i + 1][j - books[i][0]][1] = dp[i][j][1];
                            }
                        }
                    }
                    if (dp[i + 1][shelfWidth - books[i][0]][0] > dp[i][j][0] + books[i][1])
                    {
                        dp[i + 1][shelfWidth - books[i][0]][0] = dp[i][j][0] + books[i][1];
                        dp[i + 1][shelfWidth - books[i][0]][1] = books[i][1];
                    }
                }
            }
        }

        for (int i = 0; i <= shelfWidth; i++)
        {
            answer = min(dp[books.size()][i][0], answer);
        }
        return answer;
    }
};