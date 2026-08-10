class Solution {
    private int[] DP;
    private int dp(int x, List<Integer> arr)
        {
            // 1번이라도 0이 있으면
            // 내가 그만큼 빼버리면 되니까 
            if (DP[x] != -1) return DP[x]; 
            int cantControl = 1;
            for (int i = arr.size() - 1; i >=0; i--)
            {
                if (arr.get(i) > x)
                {continue;}
                if (arr.get(i) == x)
                {return 1;}
                // 얘가 1이 가능하면 안됨 
                cantControl = (cantControl & dp(x - arr.get(i), arr)); 
                // 0이 하나라도 있으면 넘길 수 있음
            }
            DP[x] = (cantControl ^ 1);
            return DP[x];
        }
    public boolean winnerSquareGame(int n) {
        List<Integer> squares = new ArrayList<>();
        DP = new int[n + 1];
        Arrays.fill(DP, -1);
        
        // 1 is odd 0 is even 
        // 
        DP[1] = 1;
        // DP[2] = 0;
        // DP[3] = 1;
        for (int i = 1; i * i <= n; i++)
        {
            // 한번도 안돼야함 
            squares.add(i * i);
        }
        return dp(n, squares) == 1;
    }
}