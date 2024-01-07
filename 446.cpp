#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Solution {
    map<long long, long long> dp[1000];
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;

        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long subVal = nums[i];
                subVal -= nums[j];
                if (dp[i].find(subVal) == dp[i].end()){
                    dp[i][subVal] = 1;
                } else {
                    dp[i][subVal]++;
                }
                if (dp[j].find(subVal) != dp[j].end()){
                    ans += dp[j][subVal];
                    dp[i][subVal] += dp[j][subVal];
                }
            }
        }
        return ans;
    }
};