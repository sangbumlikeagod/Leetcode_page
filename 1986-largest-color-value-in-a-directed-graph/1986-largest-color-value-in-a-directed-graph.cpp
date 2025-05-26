class Solution {
        vector<vector<int>> adjLists; 
        vector<vector<int>> backAdjLists; 
        vector<int> currentLevel;
        vector<int> nextLevel;

public:
    int dfs(int i, vector<int>& fullVisited, vector<int>& visited)
    {
        for (int arg : adjLists[i])
        {
            if (visited[arg] != 0)
            {
                return -1;
            }
            if (fullVisited[arg] != 0)
            {
                continue;
            }
            fullVisited[arg] = 1;
            visited[arg] = 1;
            if (dfs(arg, fullVisited, visited) == -1)
            {
                return -1;
            }
            visited[arg] = 0;
        }

        return 1;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        adjLists.resize(n, vector<int> {});
        backAdjLists.resize(n, vector<int> {});
        
        vector<int> levels(n, 0);

        for (vector<int>& edge : edges)
        {
            adjLists[edge[0]].push_back(edge[1]);
            backAdjLists[edge[1]].push_back(edge[0]);
            levels[edge[0]]++;
        }

        vector<int> fullVisited(n, 0);
        for (int i = 0 ; i < n; i++)
        {
            if (fullVisited[i] == 0)
            {
                vector<int> visited(n, 0);
                visited[i] = 1;
                fullVisited[i] = 1;
                cout << '\n';
                if (dfs(i,fullVisited ,visited) == -1) 
                {
                    return -1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (levels[i] == 0)
            {   
                currentLevel.push_back(i);
            }
        }
        int answer = 0;
        vector<vector<int>> dp(n, vector<int> (26, 0));
        while (currentLevel.empty() == false)
        {
            for (int arg : currentLevel)
            {
                dp[arg][colors[arg] - 'a']++;
                for (int next : backAdjLists[arg])
                {
                    for (int alpha = 0; alpha < 26; alpha++)
                    {
                        dp[next][alpha] = max(dp[next][alpha], dp[arg][alpha]);
                    }
                    levels[next]--;
                    if (levels[next] == 0)
                    {
                        nextLevel.push_back(next);
                    }
                }
            }
            swap(currentLevel, nextLevel);
            for (int arg : nextLevel)
            {
                for (int alpha = 0; alpha < 26; alpha++)
                {
                    answer = max(answer, dp[arg][alpha]);
                }
            }
            nextLevel.clear();
        }
        return answer;
    }
};