class Solution {
public:
    bool makeEqual(vector<string>& words) {

        unordered_map<char, int> gogog;
        for (string& s : words){
            for(char& c : s){
                gogog[c]++;
            }
        }
        for (auto a = gogog.begin(); a != gogog.end(); a++){
            if (a -> second % words.size()){return false;}
        }
        return true;
    }
};