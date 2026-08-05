class Solution {
    private List<List<Integer>> adjLists;
    private List<List<Integer>> rAdjLists;
    private int[] contaminated;

    private void dfs(int k)
    {
        for (int l : adjLists.get(k))
        {
            if (contaminated[l] != 1)
            {
                contaminated[l] = 1;
                dfs(l);
            }
        }
    }

    private boolean isCycle(int n) {
        for (int i = 0; i < n; i++)
        {
            if (contaminated[i] == 0) continue;
            for (int arg : rAdjLists.get(i))
            {
                if (contaminated[arg] == 0)
                {
                    // System.out.println(n + " " + arg);
                    return false;
                }
            }
        }
        return true;
    }
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        adjLists = new ArrayList<>(n);
        rAdjLists = new ArrayList<>(n);

        for (int i = 0; i < n; i++)
        {  
            adjLists.add(new ArrayList<>());
            rAdjLists.add(new ArrayList<>());
        }
        // Collections.fill(adjLists, new ArrayList<>());
        // Collections.fill(rAdjLists, new ArrayList<>());
        for (int[] invo : invocations)
        {
            adjLists.get(invo[0]).add(invo[1]);
            rAdjLists.get(invo[1]).add(invo[0]);
        }
        contaminated = new int[n];
        contaminated[k] = 1;
        dfs(k);

        // System.out.println(Arrays.toString(contaminated));
        List<Integer> answer = new ArrayList<>();
        if (isCycle(n))
        {
            for (int i = 0; i < n; i++)
            {
                if (contaminated[i] == 0)
                {
                    answer.add(i);
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                answer.add(i);
            }
        }
        return answer;
    }
}