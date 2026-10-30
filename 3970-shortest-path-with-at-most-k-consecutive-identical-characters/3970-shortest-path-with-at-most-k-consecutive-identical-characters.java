class Solution {
    private PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        List<List<int[]>> adjLists = new ArrayList<>();
        for (int i = 0; i < n; i++)
        {
            adjLists.add(new ArrayList<>());
        }
        for (int[] edge : edges)
        {
            adjLists.get(edge[0]).add(
                new int[] {edge[1], edge[2]}
            );
        }

        int[][] visited = new int[n][k + 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                visited[i][j] = Integer.MAX_VALUE;
            }
        }

        visited[0][k] = 0;
        // 
        pq.add(new int[] {0, 0, k});

        while (!pq.isEmpty())
        {
            int[] now = pq.remove();
            int value = now[0];
            int idx = now[1];
            int consecutive = now[2];
            // System.out.println(Arrays.toString(now));
            if (consecutive == 0)
            {
                continue;
            }
            if (idx == n - 1)
            {
                return value;
            }
            for (int[] next : adjLists.get(idx))
            {
                int nValue = value + next[1];
                
                int nxt = next[0];
                int nConsecutive = consecutive;
                if (labels.charAt(nxt) == labels.charAt(idx))
                {
                    nConsecutive--;
                }
                else
                {
                    nConsecutive = k;
                }
                if (visited[nxt][nConsecutive] <= nValue)
                {
                    continue;
                }
                visited[nxt][nConsecutive] = nValue;
                pq.add(new int[] {nValue, nxt, nConsecutive});
            }
        }


        return -1;



    }
}