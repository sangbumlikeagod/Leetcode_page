class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        vector<vector<int>> posts;
        posts.push_back(vector<int> {0, 0});
        for (char c : blocks)
        {
            if (c == 'W')
            {
                posts.push_back(vector<int> {posts.back()[0], posts.back()[1] + 1});
            }
            else
            {
                posts.push_back(vector<int> {posts.back()[0] + 1, posts.back()[1]});             
            }
        }
        int answer = 101;
        for (int i = k; i <= blocks.size(); i++)
        {
            answer = min(answer, posts[i][1] - posts[i - k][1]);
        }
        return answer;
    }
};