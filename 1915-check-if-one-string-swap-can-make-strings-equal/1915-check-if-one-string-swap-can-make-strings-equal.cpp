class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> vecS1(26, 0);
        vector<int> vecS2(26, 0);

        for (char c : s1)
        {
            vecS1[c - 'a']++;
        }
        int atLeast = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            char c = s2[i];
            if (c != s1[i]) {atLeast++;}
            vecS2[c - 'a']++;
        }
        if (atLeast > 2) return false;
        for (int i = 0; i < 26; i++)
        {
            if (vecS1[i] != vecS2[i]) return false;
        }
        return true;
    }
};