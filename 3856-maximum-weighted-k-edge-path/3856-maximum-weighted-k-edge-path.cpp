class Solution {
    vector<vector<pair<int, int>>> adjList;
    vector<vector<set<int>>> dp;
    vector<vector<vector<int>>> visited;

public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        if (k == 0) return 0;
        dp.resize(n + 1, vector<set<int>> (k + 1));

        adjList.resize(n + 1, vector<pair<int, int>> {});


        for (vector<int>& edge : edges)
        {
            if (edge[2] < t)
            {
                dp[edge[1]][1].insert(edge[2]);
                adjList[edge[0]].push_back({edge[1], edge[2]});
            }
        }


        for (int i = 2; i <= k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (auto& [next, val] : adjList[j])
                {
                    for (int arg : dp[j][i - 1])
                    {
                        if (arg + val >= t) continue;
                        dp[next][i].insert(arg + val);
                    }
                }
            }
        }


        int answer = -1;
        for (int i = 0; i < n; i++)
        {
            if (dp[i][k].empty() == false)
            {
                // cout << *(--dp[i][k].end()) << '\n';
                // for (auto& arg : dp[i][k]) cout << (arg) << '\n';
                answer = max(*(--dp[i][k].end()), answer);
            }
        }


        return answer;
    }
};