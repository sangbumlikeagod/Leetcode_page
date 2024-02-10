#include <algorithm>
using namespace std;

class Solution
{
    int modulo = 1000000007;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int ans = 0;
        for (int i = 0; i < N)
        {
            ans += (arr[i] * pow(2, size - 1 - i)) % modulo;
            ans %= modulo;
        }
        return ans;
    }
};