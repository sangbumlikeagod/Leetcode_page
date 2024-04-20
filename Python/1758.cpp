class Solution {
public:
    int minOperations(string s) {
        int ansO = 0;
        int ansT = 0;
        bool isOdd = true;
        for (const char& c : s){
            if (isOdd)
            { 
            if (c == '0') ansO++;
            else ansT++;
            }

            else 
            {if (c == '0') ansT++;
            else {ansO++;}}
            isOdd = !isOdd;
        }
        return min(ansO, ansT);
    }
};