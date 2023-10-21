#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0){
            return vector<int>{1};
        };
        vector<int> ex = getRow(rowIndex - 1);
        vector<int> res(rowIndex + 1, 0); 
        for (int i = 0; i <= rowIndex; i++){
            if (i == 0 || i == rowIndex){
                res[i] = 1;
            } else {
                res[i] = ex[i - 1] + ex[i];
            }
        }
        return res;
    }
};

int main(){
    Solution a;
    vector<int> ves = a.getRow(1);
    for (int i = 0; i < ves.size(); i ++){
        cout << ves[i] << ' ';
    }
}