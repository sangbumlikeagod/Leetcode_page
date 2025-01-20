class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        unordered_map<int, int> mapRow;
        unordered_map<int, int> mapCol;
        vector<int> indexRow (r, c);
        vector<int> indexCol (c, r);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                mapRow[mat[i][j]] = i;
                mapCol[mat[i][j]] = j;
            }
        }
        for (int i = 0; i < r * c; i++)
        {
            indexRow[mapRow[arr[i]]]--;
            indexCol[mapCol[arr[i]]]--;

            if (indexRow[mapRow[arr[i]]] == 0 || indexCol[mapCol[arr[i]]] == 0)
                return i;
        }
        return -1;
    }
};