class Solution {
private: 
    // void addPrompt(int num, vector<vector<int>>& dp, int r, bool isAdding)
    int addPrompt(int num, vector<int>& dp, int r, bool isAdding)
    {
        // r + 1
        int ii = 0;
        int i = 1;
        int ret = 0;
        for (int ii = 0; ii < 30; ii++)
        {
            if (num & i)
            {
                if (isAdding)
                {
                    dp[ii] += 1;
                }
                else
                {
                    dp[ii] -= 1;
                }
            }

            if (dp[ii])
            {
                ret += i;
            }
            i *= 2;
        }
        return ret;
    }

    bool isGettingLess(int num, vector<int>& dp)
    {
        int ii = 0;
        int i = 1;
        
        for (int ii = 0; ii < 30; ii++)
        {
            if (num & i)
            {
                if (dp[ii] <= 1)
                {
                    printf("%d에서 막힌다\n", ii);
                    return true;
                }
            }
            i *= 2;
        }
        return false;
    }

    
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int l = 0, r = 0; 
        int n = nums.size();
        
        vector<int> another(32, 0);
        vector<int> dp(32, 0);
        vector<int> answer;

        int localMax;
        for (int num : nums)
            {
                localMax = addPrompt(num, another, r, true);
            }
        // x에서 시작했을때의 최소를 알아야한다 prefixsum으로 구하고 
        int lastVal = -1;
        int maxx = 0;
        for (int num : nums)
            {
                maxx |= num;
            }

        // 그 구간의 최대를 구하고 
        while (l < n)
            {
                

                while (r < n && lastVal < localMax)
                    {
                    lastVal = addPrompt(nums[r++], dp, 0, true);
                    }

                // cout << localMax << ' ' << l << ' ' << r << '\n';
                lastVal = addPrompt(nums[l], dp, l, false);
                answer.push_back(max(1, r - l));
                localMax = addPrompt(nums[l], another, r, false);
                l++;
                
            }

        

        return answer;
    }
};