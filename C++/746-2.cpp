#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    vector visited;

public:
    int Solution::dp(int num)
    {
        if (this.visited[num])
        {
            return this.visited[num]
        }
        if (num == this.visitied.size() - 1)
        {
            return 0;
        }
        else if (num >= this.visited.size())
        {
            return 100000000;
        }
        int p1 = cost[num] + dp(num + 1);
        int p2 = cost[num] + dp(num + 2);
        if (p1 >= p2)
        {
            this.visited[num] = p2;
        }
        else
        {
            this.visited[num] = p1;
        }
        return this.visited[num];
    };

    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> visited(cost.size(), 0);
        // cout << cost.size();
        // printf("cost의 사이즈는 %d \n", cost.size());
        // for (int i = 0; i < cost.size(); i++)
        // {
        //     cout << visited[i];
        // }
        int p1 = dp(0);
        int p2 = dp(1);
        if (p1 >= p2){
            return p2;
        } else {
            return p1;
        }
    }; 
};  

int main(){
    Solution a;
    vector<int> cost = {10, 15, 20};
    public vector<int> visited(cost.size(), 0);
    a.minCostClimbingStairs(cost);
    return 0;
}