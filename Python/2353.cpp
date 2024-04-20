#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;


class FoodRatings {
    vector<priority_queue<tuple<int, string, int>, vector<tuple<int, string, int>>, greater<tuple<int, string, int>>>> rankingSys; 
    vector<int> version;
    unordered_map<string, int> catrgory;
    unordered_map<string, int> menu;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int size = foods.size();
        version.resize(size, 0);
        rankingSys.resize(size, 0);
        for (int i = 0; i < size; i++)
        {
            menu[foods[i]] = i;
            if(category.find(cuisines[i]) == category.end()){
                rankingSys[i] = priority_queue<tuple<int, string, int>, vector<tuple<int, string, int>>, greater<tuple<int, string, int>>> tmp;
            }
            
        }
        
        rankingSys.
    }
    
    void changeRating(string food, int newRating) {
        
    }
    
    string highestRated(string cuisine) {
        
    }
};
