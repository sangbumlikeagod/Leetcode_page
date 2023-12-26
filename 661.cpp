class Solution {
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m, n;
        m = img.size();
        n = img[0].size();
        vector<vector<int>> ans = vector<vector<int>> (m, vector<int> (n, 0));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int val = img[i][j];
                int cnt = 1;
                for (int k = 0; k < 8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k]; 
                    if (( 0 <= nx && nx < m) && ( 0 <= ny && ny < n) ) {
                        val += img[nx][ny];
                        cnt++;}
                ans[i][j] = val / cnt;
                }
            }
        }
        return ans;

    }
};