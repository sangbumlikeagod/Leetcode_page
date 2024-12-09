class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        bool isEven = nums[0] % 2;
        bool wasEven = !isEven;
        vector<int> putThings {};
        for (int i = 0; i < nums.size(); i++)
        {
            bool willEven = i < nums.size() - 1 ? nums[i + 1] % 2 : !isEven;
            if (isEven == wasEven)
            {
                putThings.push_back(i * 2 - 1);
            }
            if (willEven == isEven)
            {
                putThings.push_back(i * 2 + 1);
            }
            wasEven = isEven;
            isEven = i < nums.size() - 1 ? nums[i + 1] % 2 : false;
        }
        // for (int thing : putThings)
        // {
        //     cout << thing << ' ';
        // }
        // cout << '\n';
        vector<bool> answer {};
        for (int i = 0; i < queries.size(); i++)
        {
            vector<int> query = queries[i];
            // cout << upper_bound(putThings.begin(), putThings.end(), query[1]) - upper_bound(putThings.begin(), putThings.end(), query[0]) << '\n';
            answer.push_back(!(lower_bound(putThings.begin(), putThings.end(), query[1] * 2) - upper_bound(putThings.begin(), putThings.end(), query[0] * 2)));
        }
        return answer;
    }
};