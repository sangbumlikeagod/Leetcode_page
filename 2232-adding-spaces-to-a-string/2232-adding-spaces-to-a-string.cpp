class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer;
        auto index = spaces.begin();
        for (int a = 0; a < s.length(); a++){
            if (index != spaces.end() && a == (*index)){
                answer+= ' ';
                index++;

            }
            answer += s[a];

        }
        return answer;
    }
};