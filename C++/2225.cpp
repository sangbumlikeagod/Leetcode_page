#include <map>

using namespace std;

class Solution {
    map<int, int> round;
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        for (vector<int>& vec: matches){
            if (round.find(vec[0]) != round.end()) round[vec[0]] = 0;
            round[vec[1]]++;
        }
        vector<vector<int>> ans(2, vector<int> {});
        for (map<int, int>::iterator i = round[0].begin(); i != round[0].end(); i++){
            if (i -> second == 0) {ans[0].push_back(i -> first);}
            else if (i -> second == 1) { ans[0].push_back(i -> first); }
        }   
        return ans;
    }
};