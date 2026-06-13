class LCA {
    private int[][] arrays;
    private  int n;
    // 
    public void init(int[] parents)
    {
        n = parents.length;
        arrays = new int[n][24];
        for (int i = 0; i < parents.length; i++)
        {
            arrays[i][0] = parents[i];   
        }
        batch();
    }

    public void batch(){
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 24; j++)
            {
                if (arrays[i][j] == 0)
                {
                    continue;
                }
                arrays[i][j + 1] = arrays[arrays[i][j]][j];
            }
        }
    }

    public int findLca(int[] levels, int a, int b)
    {
        while (a != b)
        {
            if (levels[a] < levels[b])
            {
                int diff = levels[b] - levels[a];
                int x = 1;
                int x_digit = 0;

                while (diff >= x)
                {
                    if ((diff & x) == x)
                    {
                        b = arrays[b][x_digit];
                    }
                    x <<= 1;
                    x_digit++;
                }

            }
            else if (levels[a] > levels[b])
            {
                int diff = levels[a] - levels[b];
                int x = 1;
                int x_digit = 0;
                while (diff >= x)
                {
                    if ((diff & x) == x)
                    {
                        a = arrays[a][x_digit];
                    }
                    x <<= 1;
                    x_digit++;
                }

            }
            else
            {
                int x = 23;
                while (x > 0 && arrays[a][x] == arrays[b][x])
                {
                    x -= 1;
                }
                // System.out.println(a + " and " + b);
                a = arrays[a][x];
                b = arrays[b][x];
                // System.out.println("become+" +  a + " and " + b);
            }
        }

        return a;
    }
}


class Solution {
    private long[] dp = new long[100001];
    private long MODULO = (long) 1e9 + 7;

    private long DNQ(int s)
    {
        if (s == 1) return (long) 2;
        if (s == 0) return (long) 1;
        if (s == -1) return (long) 0;
        if (dp[s] != 0) return dp[s];
        
        long arg = DNQ(s / 2);
        long val = (arg * arg);
        val %= MODULO;
        if (s % 2 == 1)
        {
            val *= 2;
            val %= MODULO;
        }
        dp[s] = val;
        return dp[s] % MODULO;
    }
    private int[] visited;
    private int[] levels;

    private List<List<Integer>> adjList;
    private void findDepth(int node, int level) {
        levels[node] = level;
        for (int n : adjList.get(node))
        {
            if (visited[n] == 1) {continue;}
            visited[n] = 1;
            findDepth(n, level + 1);
        }
    }

    public int[] assignEdgeWeights(int[][] edges, int[][] queries) {
        // 길만 파악해서 가능함

        int n = edges.length + 1;
        
        visited= new int[n + 1];
        levels= new int[n + 1];
        int[] parents = new int[n + 1]; 

        adjList = new ArrayList<>();
        for (int i = 0; i <= n; i++)
        {
            adjList.add(new ArrayList<>());
        }

        for (int[] edge : edges){
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }

        visited[1] = 1;
        int[] answer = new int[queries.length];
        findDepth(1, 0);
        
        
        // 깊이 찾기
        for (int[] edge : edges)
        {
            if (levels[edge[0]] < levels[edge[1]])
            {
                parents[edge[1]] = edge[0];
            }
            else
            {
                parents[edge[0]] = edge[1];
            }
        }

        LCA lca = new LCA();
        lca.init(parents);

        for (int i = 0; i < queries.length; i++)
        {
            int commonparent = lca.findLca(
                levels,
                queries[i][0],
                queries[i][1]
            );
            int total_path = levels[queries[i][0]] + levels[queries[i][1]] -  2 * levels[commonparent];
            long tmp = DNQ(total_path - 1);
            answer[i] = (int) tmp;

        }
        // return (int) (answer);
        return answer;

    }
}