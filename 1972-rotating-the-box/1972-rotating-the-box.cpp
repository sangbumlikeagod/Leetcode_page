class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int colSize = box[0].size(), rowSize = box.size();
        vector<vector<char>> answer (colSize, vector<char> (rowSize, '.')); 

        for (int i = 0; i < rowSize; i++)
        {
            int inits = colSize - 1;
            for (int j = colSize - 1; j >= 0; j--)
            {
                char tmp = box[i][j];
                if (tmp == '#')
                {
                    answer[inits--][rowSize - 1 -i] = '#';
                }
                else if (tmp == '*')
                {
                    answer[j][rowSize - 1 - i] = '*';
                    inits = j - 1;
                }
            }
        }
        return answer;
    }
};