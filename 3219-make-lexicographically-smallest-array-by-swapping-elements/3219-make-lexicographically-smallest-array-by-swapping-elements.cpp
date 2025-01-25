class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int nSize = nums.size();
        vector<pair<int, int>> arrayIndex {};
        vector<pair<int, int>> dynamicStack {};
        vector<int> originalIndex {};
        vector<int> answer (nSize, 0);

        for (int i = 0; i < nSize; i++)
        {
            arrayIndex.push_back({nums[i], i});
        }
        arrayIndex.push_back({INT_MAX, nSize});
        sort(arrayIndex.begin(), arrayIndex.end());

        for (int i = 0; i <= nSize; i++)
        {
            if (dynamicStack.empty())
            {
                dynamicStack.push_back(arrayIndex[i]);
                originalIndex.push_back(arrayIndex[i].second);
                continue;
            }

            if (dynamicStack.back().first < arrayIndex[i].first - limit)
            {
                // cout<< i  << ' ' << arrayIndex[i].first << ' ' << arrayIndex[i].second << '\n';
                sort(originalIndex.begin(), originalIndex.end());
                sort(dynamicStack.begin(), dynamicStack.end());
                for (int j = 0; j < dynamicStack.size(); j++)
                {
                    // cout << dynamicStack[j].first << ' ' << dynamicStack[j].second << ' '  << originalIndex[j] << "\t\t";
                    answer[originalIndex[j]] = dynamicStack[j].first;
                }
                // cout << '\n';
                dynamicStack.clear();
                originalIndex.clear();
            }
            dynamicStack.push_back(arrayIndex[i]);
            originalIndex.push_back(arrayIndex[i].second);
        }
        return answer;
    }
};