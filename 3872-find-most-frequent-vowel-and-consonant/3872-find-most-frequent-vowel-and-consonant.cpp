class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> cases (26);
        for (char c : s)
            {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    cases[c - 'a']--;
                }
                else
                {
                    cases[c - 'a']++;
                }
            }

        int maxx = 0, minn = 0;
        for (int num : cases)
            {
                maxx = max(maxx, num);
                minn = min(minn, num);
            }
        return maxx - minn;
    }
};