class Solution {
    int ll;
    int rl;
public:
    bool canMakeSubsequence(string str1, string str2) {
        int l = 0, r = 0;
        ll = str1.length() , rl = str2.length();
        if (ll < rl)
        {
            return false;
        }
        return dfs(str1, str2, l, r, 2);
    }

    bool dfs(string& str1, string& str2, int l, int r, int limit)
    {
        if (r == rl)
            return true;
        while (l < ll && r < rl)
        {
            if (str1[l] == str2[r])
            {
                l++; r++;
            }
            else if ((str1[l] + 1 - 'a') % 26 == (str2[r] - 'a'))
            {
                l++; r++;
            }
            else
            {
                l++;
            }
        }
        return r == rl ? true : false;
    }
};