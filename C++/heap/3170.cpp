class Solution {
public:
    string clearStars(string s) {
        // 입력 문자에서 *을 빼면서 
        // 내 왼쪽이니까 사전순으로 하려면 가장 왼쪽에 있는 가장 작은놈을 뺴면됨 
        // 그냥 *의 개수를 확인하고 그 개수만큼 오른쪽에 있는 놈을 빼면되는데
        // 문제는 그 * 왼쪽에 있는놈들을 빼줘야함
        // 26개의 우선순위큐를 만들어서 풀면 안되나?
        // 이거 큰순으로 올텐데
        priority_queue<int> lexi[26];
        int wordSize = s.length();
        if (wordSize == 1)
        {
            return s;
        }
        for (int index = 0; index < s.length(); index++)
        {
            char c = s[index];
            if (c == '*')
            {
                for (int idx = 0; idx < 26 ; idx++)
                {
                    if (!lexi[idx].empty())
                    {
                        lexi[idx].pop();
                        wordSize -= 2;
                        break;
                    }
                }
            }
            else
            {
                lexi[c - 'a'].push(index);
            }
        }
        
        string ans = "";
        while (wordSize)
        {
            pair<int, int> mostBack = {0, -1};
            for (int idx = 0 ; idx < 26; idx++)
            {
                if (!lexi[idx].empty())
                {
                    if (lexi[idx].top() > mostBack.second)
                    {
                        mostBack = {idx, lexi[idx].top()};
                        // cout << idx << lexi[idx].size() << '\n';
                    }
                }
            }
            ans += 'a' + mostBack.first;
            // cout << ans << '\n';
            lexi[mostBack.first].pop();
            wordSize--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
};