class Solution {
private:
    int F[30][30][30], G[30][30][30];

public:
    pair<int, int> dp(int n, int f, int s)
    {
        if (F[n][f][s]) {
            // F랑 G를 동기화 시켰다?
            return {F[n][f][s], G[n][f][s]};
        }
        // 둘이 정확히 대칭상황이면 1이맞지
        if (f + s == n + 1)
        {
            return {1, 1};
        }
        // 변수 여러개 초기화가 가능한 tie를 쓴다 f랑 s는 둘이 합친게 무슨 상관인건지를 모르겠는데 아마도.. 
        // 둘이 오른쪽에 치우쳐져있으면 이걸쓴다는것같고
        if (f + s > n + 1)
        {
            tie(F[n][f][s], G[n][f][s]) = dp(n, n + 1 - s, n + 1 -f);
            return {F[n][f][s], G[n][f][s]};
        }

        int earliest = INT_MAX, latest = INT_MIN;
        int n_half = (n + 1) / 2;
        if (s <= n_half)
        {
            for (int i = 0; i < f; ++i)
            {
                for (int j = 0; j < s - f; ++j)
                {
                    auto [x, y] = dp(n_half, i + 1, i + j + 2);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        }
        else
        {
            // 굳이 반을넘어가는 점은 다시 왼쪽으로 돌리고 다시 계산하려한다 
            int s_prime = n + 1 - s;
            // 오른쪽을 넘어가는 자리에있다면 왼쪽으로 옮김
            int mid = (n - 2 * s_prime + 1) / 2;
            // 이건뭐지? mid 자체가 둘의 사이일것이라는거지
            for (int i = 0; i < f; ++i)
            {
                for (int j = 0; j < s_prime - f; ++j)
                {
                    // 반으로 줄였을때 f 자체는 왼쪽으로 이동할 수밖에 없으니까 
                    // 반보다컸다면 이렇게된다고? 
                    auto [x, y] = dp(n_half, i + 1, i + j + mid + 2);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        }

        return {F[n][f][s] = earliest + 1, G[n][f][s] = latest + 1};

    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));
        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        auto [earliest, latest] = dp(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};