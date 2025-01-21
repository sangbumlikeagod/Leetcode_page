class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0;
        for (int i = 1; i < grid[0].size(); i++)
        {
            top += grid[0][i];
        }
        long long answer = top;
        long long bottom = 0;
        for (int i = 0; i < grid[1].size() - 1; i++)
        {
            bottom += grid[1][i];
            top -= grid[0][i + 1];
            answer = min(answer, max(bottom, top));
        }
        answer = min(answer, bottom);
        return answer;
    }
};