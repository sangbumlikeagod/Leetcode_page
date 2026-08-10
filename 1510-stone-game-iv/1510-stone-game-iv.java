class Solution {
    private int[] DP;
    private int dp(int x, List<Integer> arr)
        {
            // 1번이라도 0이 있으면
            // 내가 그만큼 빼버리면 되니까 
            if (DP[x] != -1) return DP[x]; 
            for (int i = arr.size() - 1; i >=0; i--)
            {
                if (arr.get(i) > x)
                {continue;}
                if (arr.get(i) == x)
                {return 1;}
                if (dp(x - arr.get(i), arr) == 0)
                {
                    DP[x] = 1;
                    return 1;
                }
            }
            DP[x] = 0;
            return DP[x];
        }
    public boolean winnerSquareGame(int n) {
        List<Integer> squares = new ArrayList<>();
        DP = new int[n + 1];
        Arrays.fill(DP, -1);
        
        // 1 is odd 0 is even 
        DP[1] = 1;
        for (int i = 1; i * i <= n; i++)
        { 
            squares.add(i * i);
        }
        return dp(n, squares) == 1;
    }
}