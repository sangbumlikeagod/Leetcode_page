class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                mp[nums[i] * nums[j]]++;
            }
        }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {

        //     }
        // }
        int answer = 0;
        for (auto arg = mp.begin(); arg != mp.end(); arg++)
        {
            answer += ((arg -> second) - 1) * (arg -> second) / 2; 
        }
        return answer * 8;
    }
};