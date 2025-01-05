class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> splitShifts(s.length() + 1, 0);
        // {INDEX, FOR/BACK, ISSTART}
        for (auto& shift : shifts)
        {
            if (shift[2])
            {
                splitShifts[shift[0]]++;
                splitShifts[shift[1] + 1]--;
            }
            else
            {
                splitShifts[shift[0]]--;
                splitShifts[shift[1] + 1]++;
            }
        }
        int index = 0;
        int total = 0;
        for (int j = 0; j < s.length(); j++)
        {
            total += splitShifts[index++];

            int prev = s[j] - 'a';
            int next = (prev + total) % 26;
            if (next < 0) next += 26;
            s[j] = 'a' + next;
            total %= 26;
        }
        return s;
    }
};