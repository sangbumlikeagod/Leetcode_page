#include<iostream>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int lastValue = 1;
        sort(arr.begin(), arr.end());
        // for (int a: arr){
        //     cout << a << '\t';
        // }
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= lastValue)
            {
                lastValue++;
            }
        }
        return lastValue - 1;
    }
};