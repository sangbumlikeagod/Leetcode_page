class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> arrCopy = arr;
        sort(arrCopy.begin(), arrCopy.end());
        unordered_map<int, int> stage;
        int index = 1;
        for (int a : arrCopy)
        {
            if (stage.find(a) != stage.end())
                continue;
            stage[a] = index++;
        }

        vector<int> answer;
        for (int a : arr)
        {
            answer.push_back(stage[a]);
        }
        return answer;
    }
};