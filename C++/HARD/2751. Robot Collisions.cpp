class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        vector<vector<int>> sortTable;
        int size = positions.size();

        vector<int> idx(size);
        iota(idx.begin(), idx.end(), 0); // 0부터 size-1까지의 인덱스를 채움

        sort(idx.begin(), idx.end(), [&](int a, int b)
             { return positions[a] < positions[b]; });

        vector<int> afterMove;
        vector<int> answer(100001, 0);

        for (int i = 0; i < size; i++)
        {
            if (directions[idx[i]] == 'R')
            {
                afterMove.push_back(idx[i]);
                continue;
            }
            while (!afterMove.empty())
            {
                int rightIndex = afterMove.back();
                if (healths[idx[i]] > healths[rightIndex])
                {
                    afterMove.pop_back();
                    healths[idx[i]]--;
                }
                else if (healths[idx[i]] == healths[rightIndex])
                {
                    healths[idx[i]] = 0;
                    afterMove.pop_back();
                    break;
                }
                else
                {
                    healths[idx[i]] = 0;
                    healths[rightIndex]--;
                    break;
                }
            }
            answer[idx[i]] = healths[idx[i]];
        }

        for (int arg : afterMove)
        {
            answer[arg] = healths[arg];
        }

        vector<int> realAnswer{};
        for (int i = 0; i < size; i++)
        {
            if (answer[i])
            {
                realAnswer.push_back(answer[i]);
            }
        }
        return realAnswer;
    }
};