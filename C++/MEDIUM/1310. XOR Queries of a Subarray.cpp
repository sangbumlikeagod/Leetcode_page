class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> prefixXORS = {arr[0]};
        for (int i = 1; i < arr.size(); i++)
        {
            prefixXORS.push_back(prefixXORS.back() ^ arr[i]);
        }

        vector<int> answer = {};
        int tmp;
        for (vector<int> query : queries)
        {
            tmp = query[0] ? prefixXORS[query[1]] ^ prefixXORS[query[0] - 1] : prefixXORS[query[1]];
            answer.push_back(tmp);
        }
        return answer;
    }
};