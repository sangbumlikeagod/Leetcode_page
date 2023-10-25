#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        vector<int> cost = Solution::solve(n);
        return (cost)[k - 1];
    }

    vector<int> solve(int n)
    {
        vector<int> ans;
        if (n == 1)
        {
            ans = {0};
            return ans;
        }
        vector<int> cost = Solution::solve(n - 1);
        // 동적배열이라는게 도대체 뭘 까 
        for (int i : cost)
        {
            if (i == 0)
            {
                ans.push_back(0);
                ans.push_back(1);
            }
            else
            {
                ans.push_back(1);
                ans.push_back(0);
            }
        }

        return ans;
    }
};