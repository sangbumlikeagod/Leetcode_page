class Solution {
    private int binarySearch(
        List<int[]> lst,
        int val
    ) {
        // System.out.println("무량공처");

        // if (lst.size() != 0)
        // {
        //     System.out.println(
        //         Arrays.toString(lst.get(0)) + " " + 
        //     val);
        // }
        int l = 0, r = lst.size();
        while (l < r)
        {   
            int m = (l + r) / 2;
            // 이미 끝난 애들은 건나뛴다.
            if (lst.get(m)[2] < val)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        // System.out.println("무량공처 "+ l);
        return l;
    }
    public int minTime(int n, int[][] edges) {
        
        List<List<int[]>> adjLists = new ArrayList<>();
        for (int i = 0; i < n; i++)
        {
            adjLists.add(new ArrayList<>());
        }
        
        for (int[] edge : edges)
        {
            adjLists.get(edge[0]).add(
                new int[] {edge[1] , edge[2], edge[3]}
            );
        }

        // int[][] visited = new int[n][0];
        for (int i = 0; i < n; i++)
        {
            Collections.sort(adjLists.get(i), (a, b) -> a[2] - b[2]);  
        //     visited[i] = new int[adjLists.get(i).size()];
        //     Arrays.fill(visited[i], Integer.MAX_VALUE);
        }

        // visited가 int[] 인게 더 낫지 않나?
        // 노드 들어가는 것으로 판단하는것이 대부분이기 때문에, 
        int[] visited = new int[n];
        Arrays.fill(visited, Integer.MAX_VALUE);
        visited[0] = 0;



        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );
        pq.add(new int[] {0, 0});
        while (!pq.isEmpty())
        {
            int[] next = pq.poll();
            int time = next[0];
            int node = next[1];
            // System.out.println(time + " " + node);
            if (time > visited[node]) continue;
            if (node == n - 1)
            {
                return time;
            }
            List<int[]> lst = adjLists.get(node);
            for (int x = binarySearch(lst, time); x < lst.size(); x++)
            {
                int[] nxt = lst.get(x);
                int minPossibleTime = Math.max(time + 1, nxt[1] + 1);

                if (minPossibleTime < visited[nxt[0]])
                {
                    
                    visited[nxt[0]] = minPossibleTime;
                    // 여기에 들어갈 수있는 최소시간은 
                    // binarySearch 로 인해 이미 끝난 애들은 안걸러도 된다는게 보장됨 
                    // int minPossibleTime = Math.max(time + 1,  nxt[2]);

                    pq.add(new int[] {minPossibleTime, nxt[0]});
                }
            }

            // break;
        }
        return -1;
    }
}