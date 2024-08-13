class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<vector<int>>> answers(31, vector<vector<int>>{});
        vector<int> counting(31, 0);

        for (int candidate : candidates)
        {
            if (candidate <= 30)
                counting[candidate]++;
        }
        answers[0].push_back({});
        for (int i = 1; i <= target; i++)
        {
            vector<vector<vector<int>>> tmpAnswers(31, vector<vector<int>>{});
            for (int j = 1; j <= counting[i]; j++)
            {
                for (int k = 0; k <= target - (i * j); k++)
                {
                    for (vector<int> arg : answers[k])
                    {
                        vector<int> tmp = arg;
                        for (int jT = j; jT; jT--)
                        {
                            tmp.push_back(i);
                        }
                        // answers[k + (i * j)].push_back(tmp);
                        tmpAnswers[k + (i * j)].push_back(tmp);
                    }
                }
            }

            for (int j = 1; j <= target; j++)
            {
                for (vector<int> arg : tmpAnswers[j])
                    answers[j].push_back(arg);
            }
        }
        return answers[target];
    }
};