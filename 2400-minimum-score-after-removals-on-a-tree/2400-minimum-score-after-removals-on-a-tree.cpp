class Solution {

private: 
    int dfs(int node, vector<int>& vals, vector<int>& nums, vector<vector<int>>& adjList, vector<int>& visited)
    {
        int me = nums[node];
        for (int next : adjList[node])
        {
            if (visited[next] == 0)
            {
                visited[next] = 1;
                me ^= dfs(next, vals, nums, adjList, visited);
            }
        }
        return vals[node] = me;
    }

    bool lcas(vector<vector<int>>& lca, int l, int r, vector<int>& levels)
    {
        // printf("%d, %d 2개의 레벨을 찾는다\n", l, r);
        int ll = levels[l], lr = levels[r];
        // printf("각각의 레벨은 %d, %d이다\n", ll, lr);
        if (ll > lr)
        {
            // printf("%d이, %d 보다 작기때문에 바꾼다\n", ll, lr);
            swap(ll, lr);
            swap(l, r);
        }
        // 항성 lr이 크다고했다 그말은 밑의층이라는것
        int aa = 512;
        int aa_s = 9;
        // printf("두개의 레벨차이는 다음과 같다. %d \n", lr - ll);
         while (aa)
        {
            if ((lr - ll) & aa)
            {
                // printf("\t %d 만큼의 차이가 나기 때문에 그만큼을 채운다 %d %d \n", aa, aa_s);
                // printf("\t 이걸통해 원래 %d 였던 l값이 %d가 된다\n", l, lca[l][aa_s]);
                r = lca[r][aa_s];
            }
            aa >>= 1;
            aa_s--;
        } 
        return l == r;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adjList(n, vector<int>{});
        // 여길 채워넣는게 일

        vector<vector<int>> lca(n, vector<int>(10));
        vector<int> levels (n);
        vector<int> vals (n);
        vector<int> visited (n);


        for (vector<int>& edge: edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int s = 0;
        int gLevel = 0;
        queue<int> q;
        queue<int> q_next;
        q.push(s);
        while (true)
        {            
            while(q.empty() == false)
            {
                int ne = q.front();
                visited[ne] = 1;
                levels[ne] = gLevel;
                q.pop();
                for (int nn : adjList[ne])
                {
                    if (visited[nn]) continue;
                    q_next.push(nn);
                    lca[nn][0] = ne;
                }
            }
            gLevel++;
            swap(q, q_next);
            if (q.empty())
            {
                break;
            }
        }
        visited = vector<int>(n);
        visited[0] = 1;
        dfs(0, vals, nums, adjList, visited);
        int en = edges.size();

        for (int lev = 0; lev < 9; lev++)
        {
            for (int i = 1; i < n; i++)
            {
                lca[i][lev + 1] = lca[lca[i][lev]][lev];
            }
        }

        for (int val : vals)
            {
                cout << val << '\t';
            }
        cout << '\n';

        int answer = INT_MAX;
        for (int i = 0; i < en; i++)
        {
            for (int j = i + 1; j < en; j++)
            {
                // 두개중에 더 레벨이 낮은 edge를 먼저한다.
                //vals[a0] 아니 근데 생각해보니 부모도 알아야하네 
                // 왜냐면 그부모를 대표하는 값을 알수가 없잖아 
                // 트리의 각 부분이 자기 부모와의 관계를 알아야하는데 
                // 둘의 공통부모가 위의놈일때만 할수있도록 
                // lca를 해야하는데? 
                // 레벨이라는건 정해져있으니 

                // 큰놈을 고르는것임 -> 밑에있는 
                int ll = levels[edges[i][0]] < levels[edges[i][1]] ? edges[i][1] : edges[i][0];
                int lr = levels[edges[j][0]] < levels[edges[j][1]] ? edges[j][1] : edges[j][0];
                int M, m;
                if (lcas(lca, ll, lr, levels))
                {
                    if (levels[ll] > levels[lr]) swap(ll, lr);
                    // cout << \t << ll 
                    int head = vals[0] ^ vals[ll];
                    int tail1 = vals[ll] ^ vals[lr];
                    int tail2 = vals[lr];

                    M = max(head, tail1);
                    M = max(M, tail2);
                    m = min(head, tail1);
                    m = min(m, tail2);
                    // cout << head << '\n';
                    // cout << tail1 << '\n';
                    // cout << tail2 << '\n';
                }
                else
                {
                    int head = vals[0] ^ vals[ll] ^ vals[lr];
                    int tail1 = vals[ll];
                    int tail2 = vals[lr];
                    
                    M = max(head, tail1);
                    M = max(M, tail2);
                    m = min(head, tail1);
                    m = min(m, tail2);
                    // cout << head << '\n';
                    // cout << tail1 << '\n';
                    // cout << tail2 << '\n';
                }
                // cout << i << ' ' << j << ' ' << lcas(lca, ll, lr, levels) << ' ' << M << ' ' << m << '\n';

                answer = min(answer, M - m);
            }
        }
        return answer;

    }
};