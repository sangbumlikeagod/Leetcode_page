class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<vector<int>> sixes (6, vector<int> {0, 0});
        vector<int> overlap (6, 0);
        int n = tops.size();
        for (int i = 0; i < n; i++)
        {
            int top = tops[i];
            int bottom = bottoms[i];
            if (top == bottom){
                overlap[top - 1]++;
            }
            sixes[top - 1][0]++;
            sixes[bottom - 1][1]++;

        }
        int answer = n;
        for (int i = 0; i < 6; i++)
        {
            if (sixes[i][0] + sixes[i][1] - overlap[i] == n)
            {
                // cout << i << '\n';
                answer = min(answer, (sixes[i][0] - overlap[i]));
                answer = min(answer, (sixes[i][1] - overlap[i]));
            }
        }
        if (answer == n)
        {
            return -1;
        }
        return answer;
    }
};