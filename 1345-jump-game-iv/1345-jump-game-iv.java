class Solution {
    private HashMap<Integer, Integer> hmap = new HashMap<>();

    public int minJumps(int[] arr) {
        int n = arr.length;
        int target = n - 1;
        HashSet<Integer>[] values = new HashSet[n]; 
        int[] visited = new int[n];

        for (int i = 0; i < n; i++)
        {
            int ar = arr[i];
            if (hmap.get(ar) == null)
            {
                int key = hmap.size();
                values[key] = new HashSet<>();
                values[key].add(i);
                hmap.put(ar, key);
            }
            else
            {
                int key = hmap.get(ar);
                values[key].add(i);
            }
        }

        Queue<Integer> q = new LinkedList<>();
        Queue<Integer> nq = new LinkedList<>();
        visited[0] = 0;
        int round = 0;
        q.add(0);

        while (q.isEmpty() == false)
        {
            while (q.isEmpty() == false)
            {
                int next = q.poll();
                if (next == target)
                {
                    return round;
                }
                if (next > 0 && visited[next - 1] == 0)
                {
                    visited[next - 1] = 1;
                    nq.add(next - 1);
                }
                if (next < target && visited[next + 1] == 0)
                {
                    visited[next + 1] = 1;
                    nq.add(next + 1);
                }
                if (hmap.get(arr[next]) != null)
                {
                    int key = hmap.get(arr[next]);
                    for (Integer arg : values[key])
                    {
                        if (visited[arg] == 0)
                        {   
                            visited[arg] = 1;
                            nq.add(arg);
                        }
                    }
                    hmap.remove(arr[next]);
                }
            }
            q = nq;
            nq = new LinkedList<>();
            round++;
        }

        return -1;
    }
}