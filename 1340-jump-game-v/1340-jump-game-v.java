class Solution {
    List<List<Integer>> adjLists;
    int[] DP;
    int n = 0;
    private Integer dp(int x, int[] arr, int d)
    {
        int ans = 0;
        if (DP[x] != 0)
        {
            return DP[x];
        }

        for (int j = x - 1; j >= Math.max(0, x - d); j--)
        {
            if (arr[j] < arr[x])
            {
                ans = Math.max(dp(j, arr, d), ans);
            }
            else
            {
                break;
            }
        }
        for (int j = x + 1; j <=  Math.min(n - 1, x + d); j++)
        {
            if (arr[j] < arr[x])
            {
                ans = Math.max(dp(j, arr, d), ans);
            }
            else
            {
                break;
            }
        }

        DP[x] = ans + 1;
        return DP[x];
    }
    public int maxJumps(int[] arr, int d) {
        n = arr.length;
        DP = new int[n];
        adjLists = new ArrayList<>();

        for (int i = 0; i < n; i++)
        {
            adjLists.add(new ArrayList<>());
        }

        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (DP[i] == 0)
            {
                dp(i, arr, d);
            }
            answer = Math.max(answer, DP[i]);
        }
        return answer;
    }
}