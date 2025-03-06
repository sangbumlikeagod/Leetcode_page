class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int nn = n * n;
        unordered_map<int, int> mapps;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mapps[grid[i][j]]++;
            }
        }
        vector<int> answer = {0, 0};
        for (int i = 1; i <= nn; i++)
        {
            if (mapps.find(i) == mapps.end())
            {
                answer[1] = i;
            }
            if (mapps[i] == 2)
            {
                answer[0] = i;
            }
        }
        return answer;
    }
};