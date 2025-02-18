class Solution {
    bool backtracking(vector<int>& visited, string& s, string& pattern, int index)
    {
        if (index == pattern.size() + 1)
        {
            int before = s[0] - '1';
            for (int i = 1; i <= pattern.size(); i++)
            {
                if (pattern[i - 1] == 'I')
                {
                    if (s[i] - '1' < before)
                    {
                        return false;
                    }
                }
                else
                {
                    if (s[i] - '1' > before)
                    {
                        return false;
                    }
                }
                before = s[i] - '1';
            }
            // cout << index << ' ' << s << '\n';
            return true;
        }
        for (int i = 0; i < 9; i++)
        {
            if (visited[i]) continue;
            visited[i] = 1;
            s += '1' + i;
            if (backtracking(visited, s, pattern, index + 1))
            {
                return true;
            }
            s.pop_back();
            visited[i] = 0;
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        string s = "";
        vector<int> visited (9, 0);
        backtracking(visited, s, pattern, 0);
        return s;
    }
};