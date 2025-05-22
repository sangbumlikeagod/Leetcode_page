
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int sz = nums.size();
        int answer = 0;
        vector<vector<int>> posts (sz + 1, vector<int>{});
        for (int i = 0; i < queries.size(); i++)
        {
            vector<int>& query = queries[i];
            posts[query[0]].push_back(i);
        }

        priority_queue<int> unqualifiedQ;
        priority_queue<int, vector<int>, greater<int>> qualifiedQ;
        int current = 0 ;
        int used = 0;
        vector<int> loss(sz + 1, 0);
        for (int i = 0 ; i < sz; i++)
        {
            // cout << i << ' ';
            current -= loss[i];
            while(unqualifiedQ.empty() == false && unqualifiedQ.top() < i)
            {
                unqualifiedQ.pop();
            }
            for (int arg : posts[i])
            {
                unqualifiedQ.push(queries[arg][1]);
            }
            while (current < nums[i])
            {
                if (unqualifiedQ.empty()) return -1;
                if (unqualifiedQ.top() < i)
                {
                    unqualifiedQ.pop();
                    continue;
                }
                loss[unqualifiedQ.top() + 1]++;
                // cout << i << ' ' << used << ' ' << unqualifiedQ.top() << '\n';
                unqualifiedQ.pop();
                current++; used++;
            }
        }
        return queries.size() - used;
    }
};
// 비상 좆같은 문제 등장
// 1 1 1 1이면 '
// 그리디적으로 써야하는 애들만 구한다면
// 각 배열에 내림차순 정렬이 되어있고 
// 계속 쌓아놨다가 그리디 적으로 사용한다 인데 