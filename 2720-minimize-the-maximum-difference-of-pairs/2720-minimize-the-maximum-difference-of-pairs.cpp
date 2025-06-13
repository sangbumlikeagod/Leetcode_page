class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (!p) return 0;
        int maxVal = 0;
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> differs;
        for (int i = 1; i < nums.size(); i++)
        {
            differs.push_back({nums[i] - nums[i - 1], i});
        }
        sort(differs.begin(), differs.end());
        int l = p - 1, r = differs.size() - 1;
        
        while (l < r)
        {
            int m = (l + r) / 2;
            map<int, int> maps;
            int cnt = 0;
            for (int j = 0; j <= m; j++)
            {
                int idx = differs[j].second;
                maps[idx]++;
                maps[idx - 1]++;
            }

            bool lastUsed = false;
            int lastIndex = -1;
            for (auto idx = maps.begin(); idx != maps.end(); idx++)
            {
                if (lastUsed == false || lastIndex != idx -> first - 1|| idx -> second == 2)
                {
                    cnt++;
                    idx++;

                    if (idx == maps.end()) {
                        cnt--;
                        break;
                    }
                    else
                    {
                        if (idx -> second == 2)
                        {
                            lastUsed = true;
                            lastIndex = idx -> first;
                        }
                    }
                }
                else
                {
                    lastUsed = false;
                }
            }
            if (cnt < p)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return differs[l].first;
    }
};