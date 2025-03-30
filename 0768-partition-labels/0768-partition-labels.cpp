class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> args(26, vector<int> {});
        vector<int> nexts(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            args[s[i] - 'a'].push_back(i);    
        }
        int idx = 0;
        int next = nexts[s[idx] - 'a'];
        int ends = args[s[idx] - 'a'][next];
        int start = -1;
        vector<int> answer{};
        while (idx < s.length())
        {
            nexts[s[idx] - 'a']++;
            next = nexts[s[idx] - 'a'];
            if (next < args[s[idx] - 'a'].size())
            {
                int next_idx = args[s[idx] - 'a'][next];
                ends = max(ends, next_idx);
            }
            else if (next == args[s[idx] - 'a'].size())
            {
                ends = max(ends, idx);
            }

            if (idx == ends)
            {
                answer.push_back(idx - start);
                start = idx;
                idx++;
                continue;
            }
            idx++;
            // cout << idx << ' ' << ends << '\n';
        }
        
        return answer;

    }
};