#include <vector>
#include <iostream>

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> zeroOne = vector<int>(m + n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                zeroOne[i] += grid[i][j];
                zeroOne[m + j] += grid[i][j];
            }
        }
        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>);
    }
};