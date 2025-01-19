class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};


        int sRow = heightMap.size();
        int sCol = heightMap[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(sRow, vector<int> (sCol, 0));
        for (int i = 0; i < sRow; i++)
        {
            pq.push(vector<int> {heightMap[i][0], i, 0});
            pq.push(vector<int> {heightMap[i][sCol - 1], i, sCol - 1});
            visited[i][sCol - 1] = 1;
            visited[i][0] = 1;
        }
        for (int j = 1; j < sCol; j++)
        {
            pq.push(vector<int> {heightMap[0][j], 0, j});
            pq.push(vector<int> {heightMap[sRow - 1][j], sRow - 1, j});
            visited[0][j] = 1;
            visited[sRow - 1][j] = 1;
        }
        int answer = 0;
        while (!pq.empty())
        {
            int height = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < sRow && 0 <= ny && ny < sCol && !visited[nx][ny] )
                {
                    visited[nx][ny] = 1;
                    if (heightMap[nx][ny] < height)
                    {
                        answer += height - heightMap[nx][ny];
                        heightMap[nx][ny] = height;
                    }
                    pq.push(vector<int> {heightMap[nx][ny], nx, ny});
                }
            }

        }
        return answer;

    }
};