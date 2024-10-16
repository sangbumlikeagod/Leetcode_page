class Solution
{
    // priority_queue<int> pq;
public:
    vector<long long> maximumCoins(vector<int> &heroes, vector<int> &monsters, vector<int> &coins)
    {
        int n = heroes.size(), m = monsters.size();
        vector<vector<int>> monscoins{};
        vector<vector<int>> indexedHeroes{};

        for (int i = 0; i < n; i++)
        {
            indexedHeroes.push_back({heroes[i], i});
        }
        for (int i = 0; i < m; i++)
        {
            monscoins.push_back({monsters[i], coins[i]});
        }
        sort(monscoins.begin(), monscoins.end());
        sort(indexedHeroes.begin(), indexedHeroes.end());
        int idx = 0;
        vector<long long> answer(n, 0);
        long long before = 0;
        for (int i = 0; i < n; i++)
        {
            long long next = before;
            while (idx < m && monscoins[idx][0] <= indexedHeroes[i][0])
            {
                next += monscoins[idx][1];
                idx++;
            }
            answer[indexedHeroes[i][1]] = next;
            before = next;
        }
        return answer;
    }
};