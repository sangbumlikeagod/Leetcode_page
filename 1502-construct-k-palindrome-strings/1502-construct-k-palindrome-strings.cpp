class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() == k) return true;
        else if (s.length() < k) return false;
        vector<int> countChar (26, 0);
        for (char c : s)
        {
            countChar[c - 'a']++;
        }

        int minPal = 0;
        int maxPal = 0;
        for (int i = 0; i < 26; i++)
        {
            maxPal += countChar[i];
            minPal += countChar[i] % 2;
        }
        return maxPal >= k && minPal <= k;
    }
};