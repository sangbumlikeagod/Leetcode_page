
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int size = paths.size();
        unordered_map<string, string> stringMap;
        for (int i = 0; i < size ; i++)
        {
            stringMap[paths[i][0]] = paths[i][1];
        }
        string start = paths[0][0];
        while (stringMap.find(start) != stringMap.end())
        {
            start = stringMap.find(start) -> second;
        }
        return start;
        
    }
};