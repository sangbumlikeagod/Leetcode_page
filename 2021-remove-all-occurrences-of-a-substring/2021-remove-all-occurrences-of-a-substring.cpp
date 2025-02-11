class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<char> str_vec {};
        vector<int> str_vec_cd {};
        int index = -1;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            str_vec.push_back(c);
            if (str_vec.size() >= part.length() && c == part[part.length() - 1])
            {
                // cout << i << '\n';
                int l = str_vec.size() - 1, r = part.length() - 1;
                while (r >= 0)
                {
                    if (str_vec[l] != part[r])
                    {
                        break;
                    }
                    l--; r--;
                }
                if (r != -1)
                {
                    continue;
                }
                for (int i = 0; i < part.length(); i++)
                {
                    str_vec.pop_back();
                }
            }
        }
        string answer;
        for (char c : str_vec)
        {
            answer += c;
        }
        return answer;
    }
};