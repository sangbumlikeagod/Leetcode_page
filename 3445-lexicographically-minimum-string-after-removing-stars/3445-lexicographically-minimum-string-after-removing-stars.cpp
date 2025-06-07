class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> indexes (26, vector<int>{});
        for (int i = 0; i < s.length(); i++)
            {
                char c = s[i];
                if (c != '*')
                {
                    indexes[c - 'a'].push_back(i);
                }
                else
                {
                    for (int j = 0; j < 26; j++)
                        {
                            if (indexes[j].empty() == false)
                            {
                                indexes[j].pop_back();
                                break;
                            }
                        }
                }
            }

        vector<pair<int, char>> align; 
            for (int j = 0; j < 26; j++)
            {
                while (indexes[j].empty() == false)
                {
                    align.push_back({indexes[j].back(), 'a' + j});
                    indexes[j].pop_back();
                }
            }
        string answer = "";
        sort(align.begin(), align.end());
        for (pair<int, char>& arg : align)
            {
                answer += arg.second;
            }
        return answer;
        
    }
};