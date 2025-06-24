class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> answerset;
        for (int i = 0; i < n; i++)
            {
                if (nums[i] == key)
                {
                    for (int j = max(0, i - k); j < min(n, i + k + 1); j++)
                    {
                        answerset.insert(j);
                    }
                }
            }
        vector<int> answer;
        for (auto k = answerset.begin(); k != answerset.end(); k++)
        {
            answer.push_back(*k);
        }
        return answer;
    }
};