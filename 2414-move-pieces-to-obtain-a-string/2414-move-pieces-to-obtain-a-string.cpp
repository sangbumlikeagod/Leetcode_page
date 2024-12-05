class Solution {
public:
    bool canChange(string start, string target) {
        int l = 0, r = 0;
        while(l < start.length() && r < target.length())
        {
            while(l < start .length() && start[l] == '_')
            {
                l++;
            }
            while(r < target.length() && target[r] == '_')
            {
                r++;
            }
            // cout << l << ' ' << r << '\n';
            if (start[l] != target[r])
            {
                return false;
            }
            if (start[l] == 'L' && l < r)
            {
                return false;
            }
            if (start[l] == 'R' && l > r)
            {
                return false;
            }
            l++; r++;
        }
        // cout << l << ' ' << r << '\n';
        while(l < start.length())
        {
            if (start[l] != '_')
            {
                return false;
            }
            l++;
        }
        while(r < target.length())
        {
            if (target[r] != '_')
            {
                return false;
            }
            r++;
        }
        return true;
    }
};