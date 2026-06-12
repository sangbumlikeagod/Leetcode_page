class Solution {
    private List<List<Integer>> adjList;
    int[] visited = new int[100001];
    long MODULO = (long) (1e9) + 7;
    private int findDepth(int node) {
        int ret = 0;
        for (int n : adjList.get(node))
        {
            if (visited[n] == 1) {continue;}
            visited[n] = 1;
            ret = Math.max(ret, findDepth(n) + 1);
        }
        return ret;
    }
    public int assignEdgeWeights(int[][] edges) {
        // 홀짝 짝홀 
        // 길만 파악해서 가능함
        adjList = new ArrayList<>();
        for (int i = 0; i < 100001; i++)
        {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges){
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        visited[1] = 1; 
        int maxDepth = findDepth(1);
        // System.out.println(maxDepth);
        long answer = 1;
        for (int i = 0; i < maxDepth - 1; i++)
        {
            answer <<= 1;
            answer %= MODULO;   
        }
        return (int) (answer);
    }
}