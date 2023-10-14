#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution {
public:
    int minCostClimbingStairs(vector<int>& cost){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_qu_g;
        p_qu_g.push(make_pair(cost[0], 0));
        p_qu_g.push(make_pair(cost[1], 1));
        vector<int> visited(cost.size(), 1000000);
        // cout << visited[0];

        while (p_qu_g.size()){
            pair<int, int> tmp = p_qu_g.top();
            if (tmp.second >= cost.size()) {
                return tmp.first;
            }
            cout << tmp.first << ' ' << tmp.second << ' ';
            if (tmp.first + cost[tmp.second] < visited[tmp.second + 1]){
                visited[tmp.second + 1] = tmp.first + cost[tmp.second + 1];
                p_qu_g.push(make_pair(tmp.first + cost[tmp.second + 1], tmp.second + 1));
            }
            if (tmp.first + cost[tmp.second] < visited[tmp.second + 2]){
                visited[tmp.second + 2] = tmp.first + cost[tmp.second + 2];
                p_qu_g.push(make_pair(tmp.first + cost[tmp.second + 2], tmp.second + 2));
            }
            p_qu_g.pop();
        }
        return 0;
    };
};

int main(){
    // priority_queue<int, vector<int>, greater<int>> p_qu_g;
    // p_qu_g.push(1);
    // p_qu_g.push(9);
    // p_qu_g.push(5);
    // int sz = p_qu_g.size();
    // for (int i = 0; i < sz; i++)
    // {
    //     cout << p_qu_g.top() << ',';
    //     p_qu_g.pop();
    //     cout << '\n';
    // }
    solution a;
    vector<int> v =  {10, 15, 20};
    // v = {1,100,1,1,1,100,1,1,100,1};
    cout << a.minCostClimbingStairs(v);
}