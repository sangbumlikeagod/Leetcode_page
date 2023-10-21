#include <iostream>
#include <vector>

using namespace std;

class Fight 
{
public:
    Fight(){
    popi = {}; 
    }
    Fight(vector<int> cost){
    popi = cost;
    }
    void pi(){
        for(int i = 0; i <= popi.size(); i++){
            cout<< popi[i] << endl;
        }
    };

private:
    vector<int> popi;
};

int main(){
    vector cost = {10, 15, 20};
    Fight fight;
    vector<int> name = {2, 3, 4};
    Fight fight2(name);
    Fight fight3(vector<int> {2, 3, 4});
    fight3.pi();
    // printf("%d", fight2.popi.size());
}