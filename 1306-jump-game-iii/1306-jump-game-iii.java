class Solution {
    private int[] visited;
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        visited = new int[n];

        Queue<Integer> q = new LinkedList<>();
        Queue<Integer> nq = new LinkedList<>();
        q.add(start);
        
        while(!q.isEmpty())
        {
            while (!q.isEmpty())
            {
                int next = q.poll();
                if (arr[next] == 0)
                {
                    return true;
                }
                if (
                    next - arr[next] >= 0 && 
                    visited[next - arr[next]] == 0
                )
                {
                    visited[next - arr[next]] = 1;
                    nq.add(next - arr[next]);
                }

                if (
                    next + arr[next] < n && 
                    visited[next + arr[next]] == 0
                )
                {
                    visited[next + arr[next]] = 1;
                    nq.add(next + arr[next]);
                }
            }
            q = nq;
            nq = new LinkedList<>();
        }

        return false;
    }
}