class Solution {
    private List<List<int[]>> adjList;
    private boolean dijkstra(int n, long k, int l)
    {
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> (int) (a[0] - b[0]));
        long[] visited = new long[n];
        Arrays.fill(visited, (long) 1e15 + 7);
        pq.add(new long[] {0, 0});
        visited[0] = 0;
        while (!pq.isEmpty())
        {
            long[] next = pq.poll();
            long val = next[0]; int nd = (int) next[1];
            if (val > k) continue; 
            if (visited[nd] < val) continue;
            if (nd == n - 1) 
            {
                return true;            
            }
            
            for (int[] nn : adjList.get(nd))
            {
                if (nn[1] < l) continue;
                if (
                        val + nn[1] <= k && 
                        val + nn[1] < visited[nn[0]]
                    )
                {
                    visited[nn[0]] = val + nn[1];
                    pq.add(new long[] {val + nn[1], (long) nn[0]});
                }
            }

        }
        return false;

    }
    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        adjList = new ArrayList<>();
        int n = online.length;
        if (edges.length == 0) return -1;
        
        for (int i = 0; i < n; i++)
        {
            adjList.add(new ArrayList<>());
        }

        for (int[] edge : edges)
        {
            if (online[edge[0]] && online[edge[1]])
            {
                adjList.get(edge[0]).add(new int[] {edge[1], edge[2]});
            }
        }
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);
        int l = 0, r = edges.length - 1;
        while (l < r)
        {
            int m = (l + r) / 2 + (l + r) % 2;
            if (dijkstra(n, k, edges[m][2]))
            {
                l = m;
            }
            else
            {
                r = m - 1;
            }
        }
        return dijkstra(n, k, edges[l][2])?  edges[l][2] : -1;
    }
}