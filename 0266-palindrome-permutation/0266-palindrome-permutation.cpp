class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> args(27, 0);
        for (char c : s)
        {
            args[c - 'a']++;
        }
        int chance = 1;
        for (int arg : args)
        {
            if (arg % 2)
            {
                if (chance)
                {
                    chance = 0;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};