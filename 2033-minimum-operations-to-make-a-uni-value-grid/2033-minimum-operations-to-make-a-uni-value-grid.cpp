class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        // 웬만하면 최소값으로 찾고시은데

        vector<int> gridLine {};
        int action = grid.size() * grid[0].size();

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                gridLine.push_back(grid[i][j]);
            }
        }
        sort(gridLine.begin(), gridLine.end());
        int sample = gridLine[0];
        int totalPlus = 0;
        int totalMinus = 0;

        int count = 1;
        for (int arg : gridLine)
        {
            if ((arg - sample) % x != 0)
            {
                return -1;
            }
            totalMinus += (arg - sample) / x;
        }
        int answer = totalMinus;

        // cout << totalPlus << ' ' << totalMinus << '\n';
        while (true)
        {
            int cross = (int)(upper_bound(gridLine.begin(), gridLine.end(), sample + count * x - 1) - gridLine.begin());
            if ( (gridLine.size() - (cross)) < cross) break;
            totalMinus -= (gridLine.size() - (cross));
            totalPlus += cross;
            count++;
            answer = min(answer, totalPlus + totalMinus);
            // cout << count << ' ' << totalPlus << ' ' << totalMinus << '\n';
        }
        return answer;
    }
};