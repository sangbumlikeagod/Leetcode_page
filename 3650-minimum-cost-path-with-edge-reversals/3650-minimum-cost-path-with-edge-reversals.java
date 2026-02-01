class Solution {
    public int minCost(int n, int[][] edges) {
        HashMap<Integer, Integer>[] Costs= new HashMap[n];
        PriorityQueue<List<Integer>> pq = new PriorityQueue<>((x, y) -> x.get(0) - y.get(0));

        int[] visited = new int[n];

        for (int i = 0; i < n; i++)
        {
            Costs[i] = new HashMap<>();
        }

        for (int[] edge : edges)
        {
            Costs[edge[0]].put(edge[1], Math.min(
                    Costs[edge[0]].getOrDefault(edge[1], Integer.MAX_VALUE),
                    edge[2]
                )
            );

            Costs[edge[1]].put(edge[0], Math.min(
                    Costs[edge[1]].getOrDefault(edge[0], Integer.MAX_VALUE),
                    edge[2] * 2
                )
            );
        }

        pq.add(List.of(0, 0));
        while (!pq.isEmpty())
        {
            List<Integer> next = pq.poll();
            int cost = next.get(0);
            int node = next.get(1);

            if (visited[node] == 1)
            {
                continue;
            }
            if (node == n - 1)
            {
                return cost;
            }


            visited[node] = 1;
            for (Integer nnext : Costs[node].keySet())
            {
                if (visited[nnext] == 0)
                {
                    pq.add(
                        List.of(cost + Costs[node].get(nnext), nnext)
                    );
                }
            }
        }


        return -1;
    }
}