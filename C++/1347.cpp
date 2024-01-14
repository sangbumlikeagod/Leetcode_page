class Solution {
public:
    int alphabet[26];
    int minSteps(string s, string t) {
        for(char c: s){
            alphabet[c - 'a']++;
        }
        int ans = 0;
        for(char c: t){
            if (alphabet[c - 'a']){
                alphabet[c - 'a']--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};