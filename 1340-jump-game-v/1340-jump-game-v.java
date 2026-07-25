class Solution {
    List<List<Integer>> adjLists;
    int[] DP;
    private Integer dp(int x)
    {
        int ans = 0;
        if (DP[x] != 0)
        {
            return DP[x];
        }
        for (int poss : adjLists.get(x))
        {
            ans = Math.max(ans, dp(poss));
        }
        DP[x] = ans + 1;
        return DP[x];
    }
    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        DP = new int[n];
        adjLists = new ArrayList<>();

        for (int i = 0; i < n; i++)
        {
            adjLists.add(new ArrayList<>());
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= Math.max(0, i - d); j--)
            {
                if (arr[j] < arr[i])
                {
                    adjLists.get(i).add(j);
                }
                else
                {
                    break;
                }
            }
            for (int j = i + 1; j <=  Math.min(n - 1, i + d); j++)
            {
                if (arr[j] < arr[i])
                {
                    adjLists.get(i).add(j);
                }
                else
                {
                    break;
                }
            }
        }   

        // for (int i = 0; i < n; i++)
        // {
        //     System.out.println(adjLists.get(i));
        // }
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (DP[i] == 0)
            {
                dp(i);
            }
            answer = Math.max(answer, DP[i]);
        }
        return answer;
    }
}