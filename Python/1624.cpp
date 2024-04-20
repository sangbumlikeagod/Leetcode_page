class Solution {
public:
    unordered_map<char, int> chart;
    int maxLengthBetweenEqualCharacters(string s) {
        int idx = 0;
        int val = -1;
        for(char c : s){
            if (chart.find(c) == chart.end()){
                chart[c] = idx;
            } else {
                val = max(val, idx - chart[c] - 1);

            }
            idx++;
        }
        return val;
    }
};