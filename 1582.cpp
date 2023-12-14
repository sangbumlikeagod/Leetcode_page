#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int size = min(m, n);
        int ans = 0;
        vector<int> checkrow (m, 0);
        vector<int> checkcol (n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 1){
                    checkrow[i]++;
                    checkcol[j]++;
                }

            }
        }
        for (int p = 0; p < m; p++){
            for (int q = 0; q < n; q++){
                if (checkrow[p] == 1 & checkcol[q] == 1) ans++;
            }
        }

        return ans;

    }
};