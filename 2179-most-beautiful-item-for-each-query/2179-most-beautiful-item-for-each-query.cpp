class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> answer (queries.size(), 0);
        sort(items.begin(), items.end());
        vector<vector<int>> queries_i;
        for (int i = 0; i < queries.size(); i++)
        {
            queries_i.push_back({queries[i], i});
        }
        sort(queries_i.begin(), queries_i.end());
        int index = 0;
        int maxVal = 0;
        for (vector<int> query : queries_i)
        {
            while (index < items.size() && items[index][0] <= query[0])
            {
                maxVal = max(maxVal, items[index][1]);
                index++;
            }
            answer[query[1]] = maxVal;
        }
        return answer;

    }
};