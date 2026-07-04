class Solution {
    private List<List<int[]>> adjList;
    int[] visited;
    private int dijkstra(int n)
    {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        Arrays.fill(visited, Integer.MAX_VALUE);

        visited[0] = 0;
        pq.add(new int[] {0, 0});

        Integer minim = Integer.MAX_VALUE;
        while (!pq.isEmpty())
        {
            int[] next = pq.poll();

            // if (next[1] == n - 1)
            // {
            //     return minim;
            // }

            for (int[] arg : adjList.get(next[1]))
            {
                minim = Math.min(minim, arg[1]);
                if (next[0] + arg[1] < visited[arg[0]])
                {
                    visited[arg[0]] = next[0] + arg[1];
                    pq.add(new int[] {next[0] + arg[1], arg[0]});
                }
            }
        }
        return minim;
    }
    public int minScore(int n, int[][] roads) {
        adjList = new ArrayList<>();
        visited = new int[n];
        for (int i = 0; i < n; i++)
        {
            adjList.add(new ArrayList<>());
        }
        for (int[] road : roads)
        {
            adjList.get(road[0] - 1).add(new int[] {road[1] - 1, road[2]});
            adjList.get(road[1] - 1).add(new int[] {road[0] - 1, road[2]});
        }
        
        return dijkstra(n);
    }
}