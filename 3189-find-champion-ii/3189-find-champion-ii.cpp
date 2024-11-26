class Solution {
    vector<vector<int>> ans;
    vector<int> cnt;
    int answer = 101;
    void DFS(int x)
    {
        cnt[x] = -1;
        if (ans[x].empty())
        {
            if (answer == 101)
            {
                answer = x;   
            }
            else
            {
                answer = -1;
            }
            return;
        }
        for (int arg : ans[x])
        {
            cnt[arg]--;
            if (!cnt[arg])
            {
                DFS(arg);
            }
        }
    }
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        ans.resize(n, {});
        cnt.resize(n, 0);
        for (vector<int> edge : edges)
        {
            ans[edge[1]].push_back(edge[0]);
            cnt[edge[0]]++;
        }
        // 시그널은 ans가 비어있는데 cnt가 0일경우 
        for (int i = 0; i < n; i++)
        {
            if (!cnt[i])
            {
                DFS(i);
            }
        }
        return answer;
    }
};