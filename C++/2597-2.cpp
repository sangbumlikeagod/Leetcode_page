class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int total = pow(2, size);
        int ans = 0;
        for (int start = 1; start < total; start++)
        {
            // cout << start << "\n\n";
            int idx = 0;
            int num = 1;
            // int lastVal = -2000;
            unordered_map<int, int> lastVal;
            // vector<int> lastVal = {-2000};
            bool isPossible = true;
            while (idx < size)
            {
                if (num & start)
                {
                    if (lastVal.find(nums[idx] - k) != lastVal.end())
                    {
                        isPossible = false;
                        break;  
                    }
                }

                if (num & start)
                {
                    if (isPossible)
                    {
                        // cout << nums[idx] << '\t';
                        lastVal[nums[idx]] = 1;
                    }
                    else 
                    {
                        break;
                    }
                }


                num *= 2;
                idx++;
            }
            // cout << '\n';
            if (isPossible)
            {
                ans++;
            }
        }
        return ans;
    }
};



class Solution {
    unordered_map<int, int> ans;
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int total = pow(2, size) - 1;
        for (int start = total; start ; start--)
        {
            // cout << start << "\n\n";
            if (ans.find(start) != ans.end())
            {
                continue;
            }
            int idx = 0;
            int num = 1;
            // int lastVal = -2000;
            unordered_map<int, int> lastVal;
            // vector<int> lastVal = {-2000};
            bool isPossible = true;
            while (idx < size)
            {
                if (num & start)
                {
                    if (lastVal.find(nums[idx] - k) != lastVal.end())
                    {
                        isPossible = false;
                        break;  
                    }
                }
                if (num & start)
                {
                    if (isPossible)
                    {
                        // cout << nums[idx] << '\t';
                        lastVal[nums[idx]] = 1;
                    }
                    else 
                    {
                        break;
                    }
                }
                num *= 2;
                idx++;
            }
            // cout << '\n';
            if (isPossible)
            {
                // cout << start << '\n';
                for (int st = 1; st <= start; st++)
                {
                    if ((st & start) == st)
                    {
                        // cout << st << '\t';
                        ans[st]++;
                    }
                }
            }
        }
        return ans.size();
    }
};