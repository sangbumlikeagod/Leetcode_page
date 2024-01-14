#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
    vector<int> word1 (26, 0);
    vector<int> word2 (26, 0);
public:
    bool closeStrings(string word1, string word2) {
        for (char c : word1){
            word1[c - 'a']++;
        }
        for (char c : word2){
            word2[c - 'a']++;
        }
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        for (int i = 0; i < 26; i++)
        {
            if (word1[i] != word2[i]){
                return false;
            }
        }
        return true;
        
    }
};