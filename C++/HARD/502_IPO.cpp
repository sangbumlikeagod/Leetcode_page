class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> procap;
        priority_queue<int> maxProfitStore;
        for (int index = 0; index < capital.size(); index++)
        {
            procap.push_back({capital[index], profits[index]});
        }
        sort(procap.begin(), procap.end());
        // int startCapital = w;
        for (int index = 0; index < procap.size(); index++)
        {
            while (procap[index].first > w)
            {
                if (k == 0 || maxProfitStore.empty())
                {
                    return w;
                }
                w += maxProfitStore.top();
                maxProfitStore.pop();
                k--;
            }

            maxProfitStore.push(procap[index].second);
        }
        while (k > 0 && !maxProfitStore.empty())
        {
            w += maxProfitStore.top();
            maxProfitStore.pop();
            k--;
        }
        return w;
    }
};