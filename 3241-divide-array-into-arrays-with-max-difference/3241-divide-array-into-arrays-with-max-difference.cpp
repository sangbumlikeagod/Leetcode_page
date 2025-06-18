class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size(); i += 3)
        {
            if (nums[i] + k < nums[i + 2]) return vector<vector<int>> {};
            vector<int> tmp;
            for (int j = 0; j < 3; j++)
            {
                tmp.push_back(nums[i + j]);
            }
            answer.push_back(tmp);
        }
        return answer;
    }
};